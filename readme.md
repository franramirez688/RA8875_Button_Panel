# Button Panel Library for Arduino TFT Touch Display

Make automatically several buttons with different functionalities and draw, in your Arduino TFT Touch Display, some shapes with each one.

## Hardware

[5.0" 40-pin TFT Display - 800x480 with Touchscreen](http://www.adafruit.com/products/1596)

[RA8875 Driver Board for 40-pin TFT Touch Displays - 480x800 Max](http://www.adafruit.com/products/1590)

## Dependencies

This library depends on [fenix/ra8875_calibrate library](https://www.biicode.com/fenix/blocks/fenix/ra8875_calibrate/branches/master#.U2DEm_l_u3I) and [adafruit/ra8875 library](https://www.biicode.com/adafruit/blocks/adafruit/ra8875/branches/master/versions/0)

## Getting Started

Take a look to [biicode homepage](https://www.biicode.com) and my user [fenix](https://www.biicode.com/fenix).

Only you have to include "fenix/ra8875_button_panel/button_panel.h" and execute:

    $ bii find

All necessary will be downloaded in your ``your_bii_workspace/your_hive/depsfolder``

## Basic usage

In a sketch.cpp example you only need to declare the following lines to use this library:

    #include "fenix/ra8875_app/button_panel.h"
    ButtonPanel panel;
    ...
    void loop()
    {
        ...
        //Touch event function
        panel.OnTouch(calibrated_point); 

        //Draw all you want if you've pressed "Free" button
        panel.OnDrawFree(calibrated_point); 
    }

## Complete Example

    /******************************************************************
     This is an example for the Adafruit RA8875 Driver board for TFT displays
     ---------------> http://www.adafruit.com/products/1590
     The RA8875 is a TFT driver for up to 800x480 dotclock'd displays
     It is tested to work with displays in the Adafruit shop. Other displays
     may need timing adjustments and are not guanteed to work.
     
     Adafruit invests time and resources providing this open
     source code, please support Adafruit and open-source hardware
     by purchasing products from Adafruit!
     
     Written by Limor Fried/Ladyada for Adafruit Industries.
     BSD license, check license.txt for more information.
     All text above must be included in any redistribution.
     ******************************************************************/

    #include "fenix/ra8875_button_panel/button_panel.h"

    Adafruit_RA8875 tft = Adafruit_RA8875(RA8875_CS, RA8875_RESET);
    tsMatrix_t _tsMatrix;
    ButtonPanel panel;

    //declaring needed variables
    unsigned long previousMillis = 0;
    unsigned long interval = 100;

    void waitingTouchEvents(tsPoint_t * point);

    void setup() 
    {
        Serial.begin(9600);
        Serial.println("RA8875 start");

        /* Initialise the display using 'RA8875_480x272' or 'RA8875_800x480' */
        if (!tft.begin(RA8875_800x480)) {
        Serial.println("RA8875 Not Found!");
        while (1);
        }

        Serial.println("Found RA8875");

        tft.displayOn(true);
        tft.GPIOX(true);      // Enable TFT - display enable tied to GPIOX
        tft.PWM1config(true, RA8875_PWM_CLK_DIV1024); // PWM output for backlight
        tft.PWM1out(255);

        // With hardware accelleration this is instant
        tft.fillScreen(BLACK);
      
        pinMode(RA8875_INT, INPUT);
        digitalWrite(RA8875_INT, HIGH);

        if (readCalibrationMatrix (&_tsMatrix))
            Serial.println("Calibration is OK! :)");
        else
            Serial.println("Calibration is wrong! Repeat the process!");
      
        tft.touchEnable(true);
        panel.draw();
        
        Serial.print("Status: "); Serial.println(tft.readStatus(), HEX);
        Serial.println("Waiting for touch events ...");
    }

    void loop() 
    {
        tsPoint_t point;
        tsPoint_t calibrated;
        unsigned long currentMillis = millis();

        // waiting for touch events
        waitingTouchEvents(&point);

        /* Calcuate the real X/Y position based on the calibration matrix */
        calibrateTSPoint(&calibrated, &point, &_tsMatrix );

        //To avoid creating a lot of figures if you touch only once
        //It's not BLOCKING your Arduino
        if(currentMillis - previousMillis > interval){
            // save the last time you touched the button
            previousMillis = currentMillis;
            panel.OnTouch(calibrated);
        }   
        
        //if we touch button Free, we don't need to wait OnTouch event
        panel.OnDrawFree(calibrated);
    }



    void waitingTouchEvents(tsPoint_t* point)
    {
      /* Clear the touch data object and placeholder variables */
      memset(point, 0, sizeof(tsPoint_t));
      
      /* Clear any previous interrupts to avoid false buffered reads */
      uint16_t x, y;
      tft.touchRead(&x, &y);
      delay(1);

      /* Wait around for a new touch event (INT pin goes low) */
      while (digitalRead(RA8875_INT)){}
      
      /* Make sure this is really a touch event */
      if (tft.touched())
      {
        tft.touchRead(&x, &y);
        point->x = x;
        point->y = y;
        Serial.print("Touch: ");
        Serial.print(point->x); Serial.print(", "); Serial.println(point->y);
      }
      else
      {
        point->x = 0;
        point->y = 0;
      }
    }
/*********************************************************************************

	Enums, defines and some function which are used by the other classes

	@author: fenix 
	@email: franchuti688@gmail.com
	
					GNU GENERAL PUBLIC LICENSE

	This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 1, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA  02110-1301 USA.

*********************************************************************************/

#ifndef _CONFIG_H_
#define _CONFIG_H_


// Colors (RGB565)
#define	_RA8875_BLACK            0x0000
#define	_RA8875_BLUE             0x001F
#define	_RA8875_RED              0xF800
#define	_RA8875_GREEN            0x07E0
#define _RA8875_CYAN             0x07FF
#define _RA8875_MAGENTA          0xF81F
#define _RA8875_YELLOW           0xFFE0  
#define _RA8875_WHITE            0xFFFF


// Library only supports hardware SPI at this time
// Connect SCLK to UNO Digital #13 (Hardware SPI clock)
// Connect MISO to UNO Digital #12 (Hardware SPI MISO)
// Connect MOSI to UNO Digital #11 (Hardware SPI MOSI)
#define RA8875_INT 3
#define RA8875_CS 10
#define RA8875_RESET 9

enum Figure_types{
	TRIANGLE,
	RECTANGLE,
	CIRCLE,
	CURVE,
	ELLIPSE,
	PIXEL,
	LINE,
};

enum Colors{
	BLACK = _RA8875_BLACK, //0
	BLUE = _RA8875_BLUE,   //1  
	RED = _RA8875_RED,     //2
	GREEN = _RA8875_GREEN,   //3
	CYAN = _RA8875_CYAN,     //4
	MAGENTA = _RA8875_MAGENTA,  //5 
	YELLOW = _RA8875_YELLOW,   //6
	WHITE = _RA8875_WHITE,    //7
};


Colors getRandomColor();

#endif
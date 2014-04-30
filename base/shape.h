/*********************************************************************************

	Shape class

		Base (parent) class

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

#ifndef _OBJECT_
#define _OBJECT_

/*    Base class, abstract	 */

#include "fenix/ra8875_calibrate/ra8875_calibration.h"
#include "config.h"

class Shape: public Adafruit_RA8875
{
public:
	//constructor and destructor
	Shape():Adafruit_RA8875(RA8875_CS, RA8875_RESET)
	{
		position.x = 0;
		position.y = 0;
		color = WHITE;
	}
	virtual ~Shape(){};

	//virtual functions
	virtual void draw()=0;
	virtual void setRandomProperties(int32_t min=150, int32_t max=800){
		position.x = (uint32_t)random (min, max);
		position.y = (uint32_t)random (0, 450);
		color = getRandomColor();
	}

	/*Setting variables*/
	void setPosition(tsPoint_t pos){position = pos;}
	void setColor(Colors _color){color = _color;}

	/*Getting variables*/
	Colors getColor(){return color;}
	tsPoint_t getPosition(){return position;}

protected:
	tsPoint_t position;
	Colors color;
};

#endif

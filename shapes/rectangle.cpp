/*********************************************************************************

	Rectangle class

		Draw rectangles with adafruit_ra8875 class

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

#include "rectangle.h"

Rectangle::Rectangle()
{
	position.x = 440; position.y = 50;
	width_height.x=100;width_height.y=50;
	color = WHITE;

}

Rectangle::Rectangle(tsPoint_t w_h)
{
	if (w_h.x<0 || w_h.y<0)
	{
		w_h.x=100;
	    w_h.y=50;
	}

	width_height = w_h;
	position.x = 440; position.y = 480;
}

Rectangle::~Rectangle(){}


void Rectangle::setRandomProperties(int32_t min, int32_t max)
{
	width_height.x = (uint32_t)random (5, 150);
	width_height.y = (uint32_t)random (5, 150);
	Shape::setRandomProperties(min, max-width_height.x);
}

void Rectangle::draw()
{
	fillRect(position.x, position.y, width_height.x, width_height.y, color);
}

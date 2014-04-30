/*********************************************************************************

	Circle class

		Draw circles with adafruit_ra8875 class

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

#include "circle.h"

Circle::Circle():radio(30)
{
	position.x = 450; position.y = 200;
	color = RED;
}

Circle::Circle(int16_t r)
{
	if (r<=0)
		r = 20;
	radio = r;
	position.x = 560; position.y = 550;
}

Circle::~Circle(){}


void Circle::setRandomProperties(int32_t min, int32_t max)
{
	radio = (int)random (1, 50);
	Shape::setRandomProperties(min + radio);
}

void Circle::draw()
{
	fillCircle(position.x, position.y, radio, color);
}

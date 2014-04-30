/*********************************************************************************

	Triangle class

		Draw triangles with adafruit_ra8875 class

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

#include "triangle.h"
	
Triangle::Triangle()
{
	vertex1.x = 200;vertex1.y = 200;
	vertex2.x = 400;vertex2.y = 400;
	vertex3.x = 650;vertex3.y = 200;

	color = YELLOW;

}

Triangle::Triangle(tsPoint_t v1, tsPoint_t v2, tsPoint_t v3): 
vertex1(v1), vertex2(v2), vertex3(v3)  
{

	  
}

Triangle::~Triangle(){}


void Triangle::setRandomProperties(int32_t min, int32_t max)
{
	vertex1.x = (uint32_t) random (min, 800);
	vertex1.y = random (0, 450);

	vertex2.x = (uint32_t)random (min, 800);
	vertex2.y = (uint32_t)random (0, 450);

	vertex3.x = (uint32_t)random (min, 800);
	vertex3.y = (uint32_t)random (0, 450);

	color = getRandomColor();
}

void Triangle::draw()
{
	fillTriangle(vertex1.x, vertex1.y, vertex2.x, vertex2.y, vertex3.x, vertex3.y, color);
}

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

#ifndef _Triangle_
#define _Triangle_

#include "../base/shape.h"

class Triangle: public Shape
{
public:

	//Constructors and destructor//
	Triangle();
	Triangle(tsPoint_t v1, tsPoint_t v2, tsPoint_t v3);
	virtual ~Triangle();

	//Graphics functions
	virtual void draw();
	void setRandomProperties(int32_t min=150, int32_t max=800);
private:
	tsPoint_t vertex1;
	tsPoint_t vertex2;
	tsPoint_t vertex3;
};

#endif

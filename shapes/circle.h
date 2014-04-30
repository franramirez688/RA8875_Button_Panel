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

#ifndef _Circle_
#define _Circle_


#include "../base/shape.h"

class Circle: public Shape
{
public:

	//Constructors and destructor//
	Circle();
	Circle(int16_t r);
	virtual ~Circle();

	//Graphics functions
	virtual void draw();
	void setRandomProperties(int32_t min=150, int32_t max=800);
private:
	int16_t radio;
};

#endif

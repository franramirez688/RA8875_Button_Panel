/*********************************************************************************

	Button class

		Draw buttons with different texts to indicate its functionality

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

#ifndef _BUTTON_
#define _BUTTON_

#include "shape.h"

class Button: public Shape
{
public:

	//Constructors and destructor//
	Button();
	Button(tsPoint_t pos, tsPoint_t w_h, char _text[], Colors _color);
	virtual ~Button();

	//Graphics functions
	virtual void draw();

	/*Setting variables*/
	void setWidthHeight(tsPoint_t w_h){width_height = w_h;}
	void setText(char* _text){text = _text;}

	/*Getting variables*/
	tsPoint_t getWidthHeight(){return width_height;}

private:
	tsPoint_t width_height;
	char* text;
};

#endif

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

#include "button.h"

Button::Button():
text((char*)"Button")
{
	color = WHITE;

	position.x=0;
	position.y=0;
	width_height.x = 150;
	width_height.y = 50;
	
}


Button::Button(tsPoint_t pos, tsPoint_t w_h, char _text[], Colors _color):
text(_text)
{	
	if (w_h.x<0 || w_h.y<0)
	{
		w_h.x=0;
	    w_h.y=0;
	}
	
	if (pos.x<0 || pos.y<0)
	{
		pos.x=0;
	    pos.y=0;
	}

	color = _color;
	width_height = w_h;
	position = pos;
}

Button::~Button(){}

void Button::draw()
{
	fillRect(position.x, position.y, width_height.x, width_height.y, color);

	textMode();//activate text mode
	textSetCursor(position.x + 5, position.y+ 5);
	if (color == RED || color == MAGENTA)
		textTransparent(WHITE);
	else
		textTransparent(RED);
	textEnlarge(1);
	textWrite(text);
	graphicsMode();//activate graphics mode
}


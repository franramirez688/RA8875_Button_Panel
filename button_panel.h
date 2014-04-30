/*********************************************************************************

	ButtonPanel class

		Build easily default buttons with different functionalities

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

#ifndef _button_panel_
#define _button_panel_

#include "base/button.h"

#include "shapes/rectangle.h"
#include "shapes/circle.h"
#include "shapes/triangle.h"

enum On_Figure{ON_TRIAN, ON_RECT, ON_CIRC, ON_FREE, ON_FREE_RANDOM, ON_CLEAR, ERROR};

class ButtonPanel: public Button
{
public:

	//Constructors and destructor//
	ButtonPanel();
	virtual ~ButtonPanel();

	//Graphics functions
	void draw();
	void OnTouch(tsPoint_t pos);
	void OnDraw();
	void OnDrawFree(tsPoint_t pos);

private:
	//variables
	uint16_t width, height;
	Colors color_free_random;
	On_Figure on_figure;

	//Type buttons
	Button *trian, *circ, *rect, 
		   *free, *free_random, *clear;
};

#endif

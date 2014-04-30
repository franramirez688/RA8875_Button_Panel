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

#include "button_panel.h"

ButtonPanel::ButtonPanel()
{
	tsPoint_t pos = {0,0};
	tsPoint_t w_h = {150,50};

	trian = new Button(pos, w_h, (char*)"Triangle", WHITE);

	pos.y = pos.y + w_h.y + 10;
	circ = new Button(pos, w_h, (char*)"Circle", WHITE);

	pos.y = pos.y + w_h.y + 10;
	rect = new Button(pos, w_h, (char*)"Rectangle", WHITE);

	pos.y = pos.y + w_h.y + 10;
	free = new Button(pos, w_h, (char*)"Free", WHITE);

	pos.y = pos.y + w_h.y + 10;
	free_random = new Button(pos, w_h, (char*)"Random", WHITE);

	pos.y = pos.y + w_h.y + 10;
	clear = new Button(pos, w_h, (char*)"Clear", WHITE);

	width = w_h.x; height = w_h.y;
	on_figure = ERROR;
	color_free_random = WHITE;
}

ButtonPanel::~ButtonPanel(){}

void ButtonPanel::draw()
{
	trian->draw();
	circ->draw();
	rect->draw();
	free->draw();
	free_random->draw();
	clear->draw();
}

void ButtonPanel::OnTouch(tsPoint_t pos)
{
	//Get position buttons
	tsPoint_t trian_pos = trian->getPosition();
	tsPoint_t circ_pos = circ->getPosition();
	tsPoint_t rect_pos = rect->getPosition();
	tsPoint_t free_pos = free->getPosition();
	tsPoint_t free_random_pos = free_random->getPosition();
	tsPoint_t clear_pos = clear->getPosition();

	//Button pressed -> TRIANGLE
	if (pos.x>=trian_pos.x && pos.x<=(trian_pos.x+width) &&
		pos.y>=trian_pos.y && pos.y<=(trian_pos.y+height))
		on_figure = ON_TRIAN;
	//Button pressed -> CIRCLE
	else if (pos.x>=circ_pos.x && pos.x<=(circ_pos.x+width) &&
			pos.y>=circ_pos.y && pos.y<=(circ_pos.y+height))
		on_figure = ON_CIRC;
	//Button pressed -> RECTANGLE
	else if (pos.x>=rect_pos.x && pos.x<=(rect_pos.x+width) &&
			pos.y>=rect_pos.y && pos.y<=(rect_pos.y+height))
		on_figure = ON_RECT;
	//Button pressed -> FREE DRAWING
	else if (pos.x>=free_pos.x && pos.x<=(free_pos.x+width) &&
			pos.y>=free_pos.y && pos.y<=(free_pos.y+height))
		on_figure = ON_FREE;
	//Button pressed -> FREE DRAWING (random colors)
	else if (pos.x>=free_random_pos.x && pos.x<=(free_random_pos.x+width) &&
			pos.y>=free_random_pos.y && pos.y<=(free_random_pos.y+height))
	{
		on_figure = ON_FREE_RANDOM;
		color_free_random = getRandomColor();
		free_random->setColor(color_free_random);
		free_random->draw();
	}
	//Button pressed -> CLEAR SCREEN
	else if (pos.x>=clear_pos.x && pos.x<=(clear_pos.x+width) &&
			pos.y>=clear_pos.y && pos.y<=(clear_pos.y+height))
		on_figure = ON_CLEAR;

	//Draw figures
	OnDraw();
	
}

void ButtonPanel::OnDraw()
{
	if (on_figure == ON_TRIAN)
	{
		Triangle triangle;
		triangle.setRandomProperties();
		triangle.draw();
	}
	else if (on_figure == ON_CIRC)
	{
		Circle circle;
		circle.setRandomProperties();
		circle.draw();
	}
	else if (on_figure == ON_RECT)
	{
		Rectangle rectangle;
		rectangle.setRandomProperties();
		rectangle.draw();
	}
	else if (on_figure == ON_CLEAR)
		fillRect(width+1, 0, Adafruit_RA8875::width()-(width+2), Adafruit_RA8875::height()-1, BLACK);
}

void ButtonPanel::OnDrawFree(tsPoint_t pos)
{
	if (on_figure == ON_FREE)
	{
		if (pos.x > (width+3))
			fillCircle(pos.x, pos.y, 3, WHITE);
	}
	else if (on_figure == ON_FREE_RANDOM)
	{
		if (pos.x > (width+3))
			fillCircle(pos.x, pos.y, 3, color_free_random);
	}

}

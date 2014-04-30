/*********************************************************************************

	Enums, defines and some function which are used by the other classes

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
#include "config.h"
#include "Arduino.h"

Colors getRandomColor(){
		int val = (int)random (0, 8);
		switch (val){
		case 0:
			return BLACK;
		case 1:
			return BLUE;
		case 2:
			return RED;
		case 3:
			return GREEN;
		case 4:
			return CYAN;
		case 5:
			return MAGENTA;
		case 6:
			return YELLOW;
		case 7:
			return WHITE;
		}
}

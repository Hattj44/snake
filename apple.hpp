#pragma once
#include <ncursesw/curses.h>
#include "drawable.hpp"

class Apple : public Drawable{
	public:
		Apple(int y, int x){
			this->y = y;
			this->x = x;
			this->icon = 'A';
		}
};
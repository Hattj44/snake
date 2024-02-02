#pragma once
#include <ncursesw/curses.h>
#include "drawable.hpp"

 // Konstruktor jabłka, inicjuje pozycję y, x i ustawia ikonę na 'A'
class Apple : public Drawable{
	public:
		Apple(int y, int x){
			this->y = y;
			this->x = x;
			this->icon = 'A';
		}
};
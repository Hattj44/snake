#pragma once
#include <ncursesw/curses.h>
#include "drawable.hpp"

// Konstruktor dla pustego miejsca, inicjuje pozycję y, x i ustawia ikonę na spację (' ')
class Empty : public Drawable{
	public:
		Empty(int y, int x){
		this->y = y;
		this->x = x;
		this->icon = ' ';
		}
};
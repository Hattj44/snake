#pragma once

class Drawable{
	public:
		 // Default constructor, initializes y, x to 0 and icon to space (' ')
		Drawable(){
			y = x = 0;
			icon = ' ';
		}
		
		 // Konstruktor parametryzowany, umożliwia określenie y, x i ikony
		Drawable(int y, int x, chtype ch){
			this->y = y;
			this->x = x;
			this->icon = ch;
		}
		
		   // Funkcja pobierająca współrzędną x
		int getX(){
			return x;
		}
		
		 // Funkcja pobierająca współrzędną y
		int getY(){
			return y;
		}
		
		  // Funkcja pobierająca ikonę
		chtype getIcon(){
			return icon;
		}
		
	protected:
		int y, x;
		chtype icon;
};
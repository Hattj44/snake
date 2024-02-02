#pragma once
#include <ncursesw/curses.h>
#include "drawable.hpp"
#include <queue>

// Kierunki ruchu węża
enum Direction{
	up = -1,
	down = 1,
	left = -2,
	right = 2
};

// Klasa reprezentująca pojedynczy segment węża
class SnakePiece : public Drawable{
	public:
		 // Konstruktor domyślny, inicjuje pozycję y, x i ustawia ikonę na '#'
		SnakePiece(){
			this->x = this->y = 0;
			this->icon = '#';
		}
		 // Konstruktor parametryzowany, inicjuje pozycję y, x i ustawia ikonę na '#'
		SnakePiece(int y, int x){
			this->x = x;
			this->y = y;
			this->icon = '#';
		}
};

// Klasa reprezentująca węża
class Snake{
	std::queue<SnakePiece> prev_pieces;
	Direction cur_direction;
	
	 // Konstruktor węża, ustawia domyślny kierunek na w dół
	public:
		 // Konstruktor węża, ustawia domyślny kierunek na w dół
		Snake(){
			cur_direction = down;
		}
		
		 // Dodaje segment do węża
		void addPiece(SnakePiece piece){
			prev_pieces.push(piece);
		}
		
		 // Usuwa ostatni segment węża
		void removePiece(){
			prev_pieces.pop();
		}
		
		// Zwraca ostatni segment węża (ogon)
		SnakePiece tail(){
			return prev_pieces.front();
		}
		
		// Zwraca pierwszy segment węża (głowę)
		SnakePiece head(){
			return prev_pieces.back();
		}
		
		// Zwraca obecny kierunek węża
		Direction getDirection(){
			return cur_direction;
		}
		
		// Ustawia kierunek węża, unikając zawracania
		void setDirection(Direction d){
			if(cur_direction + d != 0)
				cur_direction = d;
		}
		
		 // Zwraca następną głowę węża na podstawie obecnego kierunku
		SnakePiece nextHead(){
			int row = head().getY();
			int col = head().getX();
			
			switch (cur_direction){
				case down:
					row++;
					break;
				case up:
					row--;
					break;
				case left:
					col--;
					break;
				case right:
					col++;
					break;
			}
			return SnakePiece(row, col);
		
		}
		
};
#pragma once
#include <ncursesw/curses.h>
#include "drawable.hpp"


class Board{
	public:
		Board(){
			 // Konstruktor domyślny, inicjuje planszę bez rozmiaru
			construct(0, 0, 300);
		}
		 // Konstruktor z parametrami, inicjuje planszę o podanych wymiarach i prędkości
		Board(int height, int width, int speed){
			construct(height, width, speed);
		}
		
		 // Inicjalizuje planszę, czyści i odświeża
		void initialize(){
			clear();
			refresh();
		}
		
		 // Dodaje obramowanie do tabla
		void addBorder(){
			box(board_win, 0, 0);
		}
		
		// Dodaje obiekt Drawable do tabla
		void add(Drawable drawable){
			addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
		}
		 
		 // Dodaje znak na określonej pozycji (y, x) do tabla
		void addAt(int y, int x, chtype ch){
			mvwaddch(board_win, y, x, ch);
		}
		
		// Pobiera wejście od użytkownika
		chtype getInput(){
			return wgetch(board_win);
		}
		
		 // Pobiera losowe puste współrzędne na tabla
		void getEmptyCoordinates(int &y, int &x){
			while((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' ')
				;
		}
		
		 // Pobiera znak na określonych współrzędnych (y, x) z tabla
		chtype getCharAt(int y, int x){
			return mvwinch(board_win, y, x);
		}
		
		void clear(){
			wclear(board_win);
			addBorder();
		}
		
		void refresh(){
			wrefresh(board_win);
		}
		
		// Ustawia timeout dla wejścia na tabla
		void setTimeout(int timeout){
		
			wtimeout(board_win, timeout);
		}
		
		// Pobiera pozycję startową wiersza
		int getStartRow(){
			return start_row;
		}
		
		// Pobiera pozycję startową kolumny planszy
		int getStartCol(){
			return start_col;
		}
		
	private:
		WINDOW *board_win;
		int height, width, start_row, start_col;
		
		  // Funkcja pomocnicza do inicjalizacji
		void construct(int height, int width, int speed){
		
		int xMax, yMax;
			getmaxyx(stdscr, yMax, xMax);
			this->height = height;
			this->width = width;
			start_row = (yMax / 2) - (height / 2);
			start_col = (xMax / 2) - (width / 2);
			
			board_win = newwin(height, width, start_row, start_col);
			setTimeout(speed);
			keypad(board_win, true);
			
	}
};
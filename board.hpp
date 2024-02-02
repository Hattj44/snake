#pragma once
#include <ncursesw/curses.h>
#include "drawable.hpp"


class Board{
	public:
		Board(){
			construct(0, 0, 300);
		}
		
		Board(int height, int width, int speed){
			construct(height, width, speed);
		}
		
		void initialize(){
			clear();
			refresh();
		}
		
		void addBorder(){
			box(board_win, 0, 0);
		}
		
		void add(Drawable drawable){
			addAt(drawable.getY(), drawable.getX(), drawable.getIcon());
		}
		 
		void addAt(int y, int x, chtype ch){
			mvwaddch(board_win, y, x, ch);
		}
		
		chtype getInput(){
			return wgetch(board_win);
		}
		
		void getEmptyCoordinates(int &y, int &x){
			while((mvwinch(board_win, y = rand() % height, x = rand() % width)) != ' ')
				;
		}
		
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
		
		void setTimeout(int timeout){
		
			wtimeout(board_win, timeout);
		}
		
		int getStartRow(){
			return start_row;
		}
		
		int getStartCol(){
			return start_col;
		}
		
	private:
		WINDOW *board_win;
		int height, width, start_row, start_col;
		
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
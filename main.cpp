#include <iostream>
#include <ncursesw/curses.h>
#include "snakeGame.hpp"
//#include "board.hpp"
//#include "drawable.hpp"

#define BOARD_DIM 12
#define BOARD_ROWS BOARD_DIM
#define BOARD_COLS BOARD_DIM * 2.5



int main(int argc, char **argv){
	
	initscr();
	refresh();
	noecho();
	curs_set(0);
	
	SnakeGame game(BOARD_ROWS, BOARD_COLS);
	
	while(!game.isOver()){
		game.processInput();
		
		game.updateState();
		
		game.redraw();
	}
	
	getch();
	endwin();
	
	std::cout << "Gameover, you get " << game.getScore() << " score" << std::endl;
	
	return 0;
}
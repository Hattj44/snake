#pragma once
#include <ncursesw/curses.h>
#include <time.h>
#include <stdlib.h>
#include "apple.hpp"
#include "empty.hpp"
#include "board.hpp"
#include "drawable.hpp"
#include "snake.hpp"
#include "scoreBoard.hpp"

class SnakeGame{
	Board board;
	bool game_over;
	Apple *apple;
	Snake snake;
	
	Scoreboard scoreboard;
	int score;
	
	// Funkcja obsługująca kolejny element węża i sprawdzająca kolizje
	void handleNextPiece(SnakePiece next){
		if(apple != NULL){
			switch(board.getCharAt(next.getY(), next.getX())){
				case 'A':
					eatApple();
					break;
				case ' ':{
					int emptyRow = snake.tail().getY();
					int emptyCol = snake.tail().getX();
					board.add(Empty(emptyRow, emptyCol));
					snake.removePiece();
					break;
			}
				default:
					game_over = true;
					break;
			}
		}
		
		board.add(next);
		snake.addPiece(next);
	}
	
	  // Funkcja tworząca jabłko i dodająca je do tabla
	void createApple(){
		int y, x;
		board.getEmptyCoordinates(y, x);
		apple = new Apple(y, x);
		board.add(*apple);		
	}
	
	 // Funkcja jedzenia jabłka i zwiększania wyniku
	void eatApple(){
		delete apple;
		apple = NULL;
		score += 100;
		scoreboard.updateScore(score);
	}
	
	public:
		// Konstruktor SnakeGame z parametrami wysokości, szerokości i prędkości
		SnakeGame(int height, int width, int speed = 300){
			board = Board(height, width, speed);
			int sb_row = board.getStartRow() + height;
			int sb_col = board.getStartCol();
			scoreboard = Scoreboard(width, sb_row, sb_col);
			initialize();
			
		}
		
		// Destruktor SnakeGame do zwalniania pamięci zajmowanej przez jabłko
		~SnakeGame(){
			delete apple;
		}
		
		// Funkcja inicjalizacji gry
		void initialize(){
			apple = NULL;
			board.initialize();
			score = 0;
			scoreboard.initialize(score);
			game_over = false;
			srand(time(NULL));
			snake.setDirection(down);
			
			handleNextPiece(SnakePiece(1, 1));
			handleNextPiece(snake.nextHead());
			handleNextPiece(snake.nextHead());
			snake.setDirection(right);
			handleNextPiece(snake.nextHead()); 
			
			if(apple == NULL){
				createApple();
			}
		}
		
		// Funkcja obsługi wejścia od użytkownika
		void processInput(){
			chtype input = board.getInput();
			switch(input){
				case KEY_UP:
				case 'w':
					snake.setDirection(up);
					break;
				case KEY_DOWN:	
				case 's':
					snake.setDirection(down);
					break;
				case KEY_RIGHT:
				case 'd':
					snake.setDirection(right);
					break;
				case KEY_LEFT:
				case 'a':
					snake.setDirection(left);
					break;
				case 'p':
					board.setTimeout(-1);
					while(board.getInput() != 'p')
						;
					board.setTimeout(1000);
					break;
				default:
					break;
			}
		}
		
		 // Funkcja aktualizacji stanu gry
		void updateState(){
		handleNextPiece(snake.nextHead());
		
		if (apple == NULL){
			createApple();
			}
		}
		
		 // Funkcja przerysowania ekranu
		void redraw(){
			board.refresh();
			scoreboard.refresh();
		}
		
		// Funkcja sprawdzająca zakończenie gry
		bool isOver(){
			return game_over;
		}
		
		 // Funkcja pobierająca aktualny wynik
		int getScore(){
			return score;
		}
	
};
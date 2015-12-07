#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "snake.h"
#include "apple.h"


typedef struct Game Game;


typedef struct Game {
    SnakeHead *snakeHead;
    Apple *apple;
}Game;

Game* initGame();
int allegroInit();
int gameRound();
int colisionApple();
Apple* placeApple();
#endif // GAME_H_INCLUDED

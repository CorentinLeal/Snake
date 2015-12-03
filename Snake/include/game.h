#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "snake.h"
#include "apple.h"
#include "map.h"


typedef struct Game Game;


typedef struct Game {
    SnakeHead *snakeHead;
    Apple *apple;
    Map *field;
}Game;

Game* initGame();
int allegroInit();
int gameRound();
int checkColisionApple();

#endif // GAME_H_INCLUDED

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
    int score;
}Game;

Game* initGame();
int allegroInit();
int gameRound();
int colisionApple();
Apple* placeApple();
int gameRound(Game *game);
int checkWallColision(Game *game);
int pause();

#endif // GAME_H_INCLUDED

#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED

typedef struct SnakeHead SnakeHead;
typedef struct SnakeBody SnakeBody;

static const int baseHealth = 3;
static const int baseSize = 7;


typedef struct SnakeHead {
    int x;
    int y;
    int direction;
    int growth;
    int health;
    SnakeBody *nextElement;
}SnakeHead;

typedef struct SnakeBody {
    int x;
    int y;
    SnakeBody *nextElement;
}SnakeBody;

int headMove(SnakeHead *snakeHead);
SnakeHead* initSnake ();
int snakeMove (SnakeHead *snakeHead);
SnakeBody *newSnakeBody (int x, int y);
int looseLife (SnakeHead *snakeHead);


#endif // SNAKE_H_INCLUDED

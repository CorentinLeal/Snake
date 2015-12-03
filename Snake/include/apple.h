#ifndef APPLE_H_INCLUDED
#define APPLE_H_INCLUDED

typedef struct Apple {
    int x;
    int y;
    int point;
    int isMagic;
}Apple;

static const int POINT_CLASSIC = 1;
static const int POINT_MAGIC = 5;
static const int MAGIC_APPLE_RATE = 10;

Apple* initApple();

#endif // APPLE_H_INCLUDED

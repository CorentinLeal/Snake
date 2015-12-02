#ifndef APPLE_H_INCLUDED
#define APPLE_H_INCLUDED

typedef struct Apple {
    int x;
    int y;
    int point;
}Apple;

static const int POINT_CLASSIC = 1;
static const int POINT_MAGIC = 1;

Apple* initApple();

#endif // APPLE_H_INCLUDED

#ifndef MAP_C_INCLUDED
#define MAP_C_INCLUDED

typedef struct Map {
    int Map[MAP_HEIGHT][MAP_WIDTH];
}Map;

static const int MAP_WIDTH = 60;
static const int MAP_HEIGHT = 50;

#endif // MAP_C_INCLUDED

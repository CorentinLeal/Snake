#ifndef MAP_C_INCLUDED
#define MAP_C_INCLUDED

#define MAP_WIDTH 32
#define MAP_HEIGHT 32

typedef struct Map {
    int field[MAP_HEIGHT][MAP_WIDTH];
}Map;

Map* initMap();

#endif // MAP_C_INCLUDED

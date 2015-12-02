#ifndef MAP_C_INCLUDED
#define MAP_C_INCLUDED

#define MAP_WIDTH 20
#define MAP_HEIGHT 20

typedef struct Map {
    int field[MAP_HEIGHT][MAP_WIDTH];
}Map;

Map* initMap();

#endif // MAP_C_INCLUDED

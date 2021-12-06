#pragma once

#include <SDL.h>
#include <iostream>
#include <windows.h>


// CellMap stores an array of cells with their states
class CellMap
{
public:
    CellMap(unsigned int w, unsigned int h);
    ~CellMap();
private:
    unsigned char* cells;
    unsigned char* temp_cells;
    unsigned int width;
    unsigned int height;
    unsigned int length_in_bytes;
};

// Cell map dimensions
unsigned int cellmap_width = 500;
unsigned int cellmap_height = 500;

// Width and height (in pixels) of a cell i.e. magnification
unsigned int cell_size = 1;

// Randomisation seed
unsigned int seed;

// Graphics
SDL_Window *window = NULL;
SDL_Surface* surface = NULL;
unsigned int s_width = cellmap_width * cell_size;
unsigned int s_height = cellmap_height * cell_size;



int main(int argc, char* argv[])
{
    
    return 0;
}

CellMap::CellMap(unsigned int w, unsigned int h)
{
    width = w;
    height = h;
    length_in_bytes = w * h;
    cells = new unsigned char[length_in_bytes];  // cell storage
    temp_cells = new unsigned char[length_in_bytes]; // temp cell storage
    memset(cells, 0, length_in_bytes);  // clear all cells, to start
}

CellMap::~CellMap()
{
    delete[] cells;
    delete[] temp_cells;
}




#include <iostream>
#include <SDL.h>


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



int main() {
    std::cout << "Hello, World!" << std::endl;
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

CellMap::~CellMap() {
    delete[] cells;
    delete[] temp_cells;
}
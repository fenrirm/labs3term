#include <iostream>
#include <SDL.h>


class CellMap
{
public:
    CellMap(unsigned int w, unsigned int h);
    ~CellMap();
    void SetCell(unsigned int x, unsigned int y);
    void ClearCell(unsigned int x, unsigned int y);
    int CellState(int x, int y);
    void NextGen();
    void Init();

private:
    unsigned char* cells;
    unsigned char* temp_cells;
    unsigned int width;
    unsigned int height;
    unsigned int length_in_bytes;
};
//cell map dimension
unsigned int cellmap_width = 500;
unsigned int cellmap_height = 500;

// Width and height (in pixels) of a cell i.e. magnification
unsigned int cell_size = 1;

// Randomisation seed
unsigned int seed;


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


void CellMap::SetCell(unsigned int x, unsigned int y)
{
    int w = width, h = height;
    int xoleft, xoright, yoabove, yobelow;
    unsigned char *cell_ptr = cells + (y * w) + x;

    // Calculate the offsets to the eight neighboring cells,
    // accounting for wrapping around at the edges of the cell map
    xoleft = (x == 0) ? w - 1 : -1;
    xoright = (x == (w - 1)) ? -(w - 1) : 1;
    yoabove = (y == 0) ? length_in_bytes - w : -w;
    yobelow = (y == (h - 1)) ? -(length_in_bytes - w) : w;

    *(cell_ptr) |= 0x01; // Set first bit to 1

    // Change successive bits for neighbour counts
    *(cell_ptr + yoabove + xoleft) += 0x02;
    *(cell_ptr + yoabove) += 0x02;
    *(cell_ptr + yoabove + xoright) += 0x02;
    *(cell_ptr + xoleft) += 0x02;
    *(cell_ptr + xoright) += 0x02;
    *(cell_ptr + yobelow + xoleft) += 0x02;
    *(cell_ptr + yobelow) += 0x02;
    *(cell_ptr + yobelow + xoright) += 0x02;
}


void CellMap::ClearCell(unsigned int x, unsigned int y)
{
    int w = width, h = height;
    int xoleft, xoright, yoabove, yobelow;
    unsigned char *cell_ptr = cells + (y * w) + x;

    // Calculate the offsets to the eight neighboring cells,
    // accounting for wrapping around at the edges of the cell map
    xoleft = (x == 0) ? w - 1 : -1;
    xoright = (x == (w - 1)) ? -(w - 1) : 1;
    yoabove = (y == 0) ? length_in_bytes - w : -w;
    yobelow = (y == (h - 1)) ? -(length_in_bytes - w) : w;


    *(cell_ptr) &= ~0x01; // Set first bit to 0

    // Change successive bits for neighbour counts
    *(cell_ptr + yoabove + xoleft) -= 0x02;
    *(cell_ptr + yoabove) -= 0x02;
    *(cell_ptr + yoabove + xoright) -= 0x02;
    *(cell_ptr + xoleft) -= 0x02;
    *(cell_ptr + xoright) -= 0x02;
    *(cell_ptr + yobelow + xoleft) -= 0x02;
    *(cell_ptr + yobelow) -= 0x02;
    *(cell_ptr + yobelow + xoright) -= 0x02;
}


int CellMap::CellState(int x, int y)
{
    unsigned char *cell_ptr =
            cells + (y * width) + x;

    // Return first bit (LSB: cell state stored here)
    return *cell_ptr & 0x01;
}
#pragma once
#include"Foundation.h"
#include <vector>

class Board {
public:
    Board(int size);  
    Board(const Board& copy);  
    ~Board()=default; 

    void Initialize(); 
    void Display() const; 
    Foundation getCell(int row, int col) const;  
    void setCell(int row, int col, const Foundation& value);


private:
    int m_size;  
    std::vector<std::vector<Foundation>> m_board;
};
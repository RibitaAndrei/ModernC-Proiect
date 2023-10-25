#pragma once
#include"Foundation.h"
#include <vector>

class Board {
public:
    Board(int size);  
    Board(const Board& copy);  
    ~Board()=default; 

private:
    int m_size;  
    std::vector<std::vector<Foundation>> m_board;
};
#include "board.h"
#include <iostream>

Board::Board(int size) 
    : m_size{ size }
{
}

Board::Board(const Board& copy) 
    : m_size{ copy.m_size },
    m_board{ copy.m_board }
{
}

Board::~Board()
{}
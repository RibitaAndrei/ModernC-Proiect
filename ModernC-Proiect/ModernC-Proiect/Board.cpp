#include "board.h"
#include <iostream>

Board::Board(int size) 
    : m_size{ size }
{}

Board::Board(const Board& copy) 
    : m_size{ copy.m_size },
    m_board{ copy.m_board }
{}

Board::~Board()
{}


Foundation Board::getCell(int row, int col) const 
{
    if (row >= 0 && row < m_size && col >= 0 && col < m_size) 
    {
        return m_board[row][col];
    }
}


void Board::setCell(int row, int col, const Foundation& value)
{
    if (row >= 0 && row < m_size && col >= 0 && col < m_size) 
    {
        m_board[row][col] = value;
    }
}
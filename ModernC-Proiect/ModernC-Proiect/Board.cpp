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

void Board::Initialize()
{
    m_board.clear();

    // Inițializează m_board cu un vector de m_size x m_size Foundation-uri.
    m_board.resize(m_size, std::vector<Foundation>(m_size, Foundation()));

    // Umple tabla de joc 
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            if (i % 2 == 0 && j % 2 == 0) {
                m_board[i][j].setVertical(true);
            }
            else if (i % 2 == 1 && j % 2 == 1) {
                m_board[i][j].setHorizontal(true);
            }
        }
    }
}

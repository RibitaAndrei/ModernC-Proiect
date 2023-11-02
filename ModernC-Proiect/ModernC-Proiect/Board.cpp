#include "board.h"
#include <iostream>

Board::Board(int size)
    : m_size{ size }
{}

Board::Board(const Board& copy)
    : m_size{ copy.m_size },
    m_board{ copy.m_board }
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


void Board::Display() const
{
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            if (i == 0 || i == m_size - 1) {
                // Prima și ultima linie
                std::cout << ".";
            }
            else if (i == 1 || i == m_size - 2) {
                // A doua și penultima linie
                if (j == 0) {
                    std::cout << ".";
                }
                else if (j == m_size - 1) {
                    std::cout << ".";
                }
                else {
                    std::cout << "-";
                }
            }
            else {
                if (j == 0 || j == m_size - 1) {
                    // Marginile stângă și dreaptă cu simbolurile "|"
                    std::cout << "|";
                }
                else {
                    // Restul tablei, cu liniile de puncte în mijloc
                    std::cout << ".";
                }
            }
        }
        std::cout << std::endl;
    }
}

void Board::Reset()
{
    // Șterge orice date existente pe tablă
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            m_board[i][j] = Foundation(); // Resetarea celulelor la starea inițială.
        }
    }
}

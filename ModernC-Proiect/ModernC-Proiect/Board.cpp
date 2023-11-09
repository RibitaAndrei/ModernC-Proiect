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

std::vector<std::vector<Foundation>> Board::GetBoard()
{
    return m_board;
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
                if (j == 0 || j == m_size - 1)
                    std::cout << "  ";
                else
                    std::cout << ". ";
            }
            else
                std::cout << ". ";
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

void Board::PlacePilon(uint8_t xFoundation, uint8_t yFoundation)
{
    m_board[xFoundation][yFoundation].MakePilon();
}

void Board::FillBridge(uint8_t xFoundation1, uint8_t yFoundation1, uint8_t xFoundation2, uint8_t yFoundation2)
{
    if (xFoundation1 - xFoundation2 == 2)
        for (uint8_t indexLine = xFoundation2 + 1; indexLine <= xFoundation1; indexLine++)
            m_board[indexLine][yFoundation1].MakeBridge();
   if (xFoundation1 - xFoundation2 == -2)
        for (uint8_t indexLine = xFoundation2 - 1; indexLine >= xFoundation1; indexLine--)
            m_board[indexLine][yFoundation1].MakeBridge();
    if (yFoundation1 - yFoundation2 == 2)
        for (uint8_t indexCol = yFoundation2 + 1; indexCol <= yFoundation1; indexCol++)
            m_board[xFoundation1][indexCol].MakeBridge();
    if (yFoundation1 - yFoundation2 == -2)
        for (uint8_t indexCol = yFoundation2 - 1; indexCol >= yFoundation1; indexCol--)
            m_board[xFoundation1][indexCol].MakeBridge();
}

void Board::PlaceBridge(uint8_t xFoundation1, uint8_t yFoundation1, uint8_t xFoundation2, uint8_t yFoundation2)
{
    m_board[xFoundation1][yFoundation1].MakeBridge();
    m_board[xFoundation2][yFoundation2].MakeBridge();
    FillBridge(xFoundation1, yFoundation1, xFoundation2, yFoundation2);
}



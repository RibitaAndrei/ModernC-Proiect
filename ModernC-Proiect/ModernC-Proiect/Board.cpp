#include "board.h"
#include <iostream>
#include <Windows.h>
#include <stack>
#include <vector>


Board::Board(int size) 
    : m_size{ size }
{
    m_board.resize(m_size);
    for (int index = 0; index < m_size; index++)
        m_board[index].resize(m_size);
}

Board::Board(const Board& copy)
    : m_size{ copy.m_size },
    m_board{ copy.m_board }
{}

Foundation Board::GetCell(int row, int col) const
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


void Board::SetCell(int row, int col, const Foundation& value)
{
    if (row >= 0 && row < m_size && col >= 0 && col < m_size)
    {
        m_board[row][col] = value;
    }
}

bool Board::IsValidPilonPlacement(uint8_t xFoundation, uint8_t yFoundation)
{
    // Verificați dacă coordonatele sunt în limitele tablei
    if (xFoundation >= 0 && xFoundation < m_size && yFoundation >= 0 && yFoundation < m_size) {
        // Verificați dacă celula este goală (nu conține deja un pilon)
        return m_board[xFoundation][yFoundation].IsEmpty();
    }
    return false; // Coordonate invalide sau celula deja ocupată
}

bool Board::HasConnection() const
{
    // Matrice pentru a marca celulele vizitate
    std::vector<std::vector<bool>> visited(m_size, std::vector<bool>(m_size, false));

    // Stiva pentru a efectua DFS
    std::stack<std::pair<int, int>> stack;

    // Pornim DFS de la prima și ultima coloană
    for (int i = 0; i < m_size; ++i)
    {
        if (!visited[i][0] && m_board[i][0].IsBridge())
        {
            stack.push({ i, 0 });
            visited[i][0] = true;
        }
        if (!visited[i][m_size - 1] && m_board[i][m_size - 1].IsBridge())
        {
            stack.push({ i, m_size - 1 });
            visited[i][m_size - 1] = true;
        }
    }

    // Pornim DFS de la prima și ultima linie
    for (int j = 0; j < m_size; ++j)
    {
        if (!visited[0][j] && m_board[0][j].IsBridge())
        {
            stack.push({ 0, j });
            visited[0][j] = true;
        }
        if (!visited[m_size - 1][j] && m_board[m_size - 1][j].IsBridge())
        {
            stack.push({ m_size - 1, j });
            visited[m_size - 1][j] = true;
        }
    }

    // Direcții posibile pentru deplasare (sus, jos, stânga, dreapta)
    const std::vector<std::pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

    // DFS
    while (!stack.empty())
    {
        auto [x, y] = stack.top();
        stack.pop();

        // Vizitează toate celulele adiacente
        for (const auto& dir : directions)
        {
            int newX = x + dir.first;
            int newY = y + dir.second;

            // Verifică dacă celula adiacentă este validă și nu a fost vizitată
            if (newX >= 0 && newX < m_size && newY >= 0 && newY < m_size && !visited[newX][newY] && m_board[newX][newY].IsBridge())
            {
                stack.push({ newX, newY });
                visited[newX][newY] = true;
            }
        }
    }
    // Verifică dacă s-au vizitat toate celulele de pe margini
    for (int i = 0; i < m_size; ++i)
    {
        if (visited[i][0] && visited[i][m_size - 1])
            return true;
    }

    for (int j = 0; j < m_size; ++j)
    {
        if (visited[0][j] && visited[m_size - 1][j])
            return true;
    }

    return false;
}

void Board::Display() const
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            if (i == 0 || i == m_size - 1) {
                // Prima și ultima linie
                SetConsoleTextAttribute(hConsole, 12);
                if (m_board[i][j].GetType() == Foundation::PieceType::Pilon)
                    std::cout << "P ";
                else if (j == 0 || j == m_size - 1)
                    std::cout << "  ";
                else
                    std::cout << ". ";
            }
            else if (j == 0 || j == m_size - 1)
            {
                SetConsoleTextAttribute(hConsole, 9);
                if (m_board[i][j].GetType() == Foundation::PieceType::Pilon)
                    std::cout << "P ";
                else 
                    std::cout << ". ";
            }
            else
            {
                SetConsoleTextAttribute(hConsole, 7);
                if (m_board[i][j].GetType() == Foundation::PieceType::Pilon)
                    std::cout << "P ";
                else 
                    std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7);
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

void Board::PlacePilon(uint16_t xFoundation, uint16_t yFoundation)
{
    m_board[xFoundation][yFoundation].MakePilon();
}

void Board::FillBridge(uint16_t xFoundation1, uint16_t yFoundation1, uint16_t xFoundation2, uint16_t yFoundation2)
{
    if (xFoundation1 - xFoundation2 == 2)
        for (uint16_t indexLine = xFoundation2 + 1; indexLine <= xFoundation1; indexLine++)
            m_board[indexLine][yFoundation1].MakeBridge();
   if (xFoundation1 - xFoundation2 == -2)
        for (uint16_t indexLine = xFoundation2 - 1; indexLine >= xFoundation1; indexLine--)
            m_board[indexLine][yFoundation1].MakeBridge();
    if (yFoundation1 - yFoundation2 == 2)
        for (uint16_t indexCol = yFoundation2 + 1; indexCol <= yFoundation1; indexCol++)
            m_board[xFoundation1][indexCol].MakeBridge();
    if (yFoundation1 - yFoundation2 == -2)
        for (uint16_t indexCol = yFoundation2 - 1; indexCol >= yFoundation1; indexCol--)
            m_board[xFoundation1][indexCol].MakeBridge();
}

void Board::PlaceBridge(uint16_t xFoundation1, uint16_t yFoundation1, uint16_t xFoundation2, uint16_t yFoundation2)
{
    m_board[xFoundation1][yFoundation1].MakeBridge();
    m_board[xFoundation2][yFoundation2].MakeBridge();
    FillBridge(xFoundation1, yFoundation1, xFoundation2, yFoundation2);
}



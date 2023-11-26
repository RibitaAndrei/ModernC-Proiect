#include "board.h"
#include <iostream>
#include <Windows.h>
#include <stack>
#include <vector>


Board::Board(int size) 
    : m_size{ size }
{
    m_board.resize(size);
    for (int index = 0; index < size; index++)
        m_board[index].resize(size);
}

Board::Board(const Board& copy)
    : m_size{ copy.m_size },
    m_board{ copy.m_board }
{}

Foundation* Board::GetCell(const int &row, const int &col) const
{
    if (row >= 0 && row < m_size && col >= 0 && col < m_size)
    {
        return m_board[row][col];
    }
}

std::vector<std::vector<Foundation*>> Board::GetBoard() const
{
    return m_board;
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
        if (!visited[i][0] && IsBridge(m_board[i][0]))
        {
            stack.push({ i, 0 });
            visited[i][0] = true;
        }
        if (!visited[i][m_size - 1] && IsBridge(m_board[i][m_size - 1]))
        {
            stack.push({ i, m_size - 1 });
            visited[i][m_size - 1] = true;
        }
    }

    // Pornim DFS de la prima și ultima linie
    for (int j = 0; j < m_size; ++j)
    {
        if (!visited[0][j] && IsBridge(m_board[0][j]))
        {
            stack.push({ 0, j });
            visited[0][j] = true;
        }
        if (!visited[m_size - 1][j] && IsBridge(m_board[m_size - 1][j]))
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

bool Board::IsCorner(const Foundation::Position& pos) const
{
    auto [row, col] = pos;
    if ((row == 0 && col == 0) ||
        (row == 0 && col == m_size - 1) ||
        (row == m_size - 1 && col == 0) ||
        (row == m_size - 1 && col == m_size - 1))
        return true;
    return false;
}

void Board::PrintCell(Foundation* f, HANDLE &hConsole) const
{
    if (IsPiece(f))
    {
        Foundation::Position cellPos = std::make_pair(f->GetRow(), f->GetColumn());
        if (IsCorner(cellPos))
        {
            std::cout << "  ";
        }
        switch (f->GetColor())
        {
        case Foundation::PlayerColor::Red:
            SetConsoleTextAttribute(hConsole, 12);
            break;
        case Foundation::PlayerColor::Black:
            SetConsoleTextAttribute(hConsole, 7);
            break;
        }
    }
    else if (IsRedBase(f))
        SetConsoleTextAttribute(hConsole, 12);
    else if (IsBlueBase(f))
        SetConsoleTextAttribute(hConsole, 7);
    else
        SetConsoleTextAttribute(hConsole, 15);

    if (IsPilon(f))
        std::cout << "P ";
    else if (IsBridge(f))
        std::cout << "B ";
    else
        std::cout << ". ";
}

void Board::ResetBoard()
{
    // Șterge orice date existente pe tablă
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {
            m_board[i][j] = Foundation(); // Resetarea celulelor la starea inițială.
        }
    }
}

void Board::PlacePilon(const Foundation::Position& posPilon, const Foundation::PlayerColor& activePlayer)
{
    auto& [row, col] = posPilon;
    delete m_board[row][col];
    m_board[row][col] = new Pilon(activePlayer, posPilon);

    std::vector<Foundation::Position> positions = AdjacentPilons(posPilon, activePlayer);
    for (int index = 0; index < positions.size(); index++)
        PlaceBridge(posPilon, positions[index], activePlayer);
}

void Board::PlaceBridge(const Foundation::Position& posFirstPilon, const Foundation::Position& posSecondPilon, const Foundation::PlayerColor& activePlayer)
{
    auto& [rowFirstPilon, colFirstPilon] = posFirstPilon;
    auto& [rowSecondPilon, colSecondPilon] = posSecondPilon;

    if (rowFirstPilon - rowSecondPilon == 2)
        for (uint8_t indexLine = rowSecondPilon; indexLine < rowFirstPilon; indexLine++)
        {
            Bridge::Pilons pilons = std::make_pair(m_board[rowFirstPilon][colFirstPilon], m_board[rowSecondPilon][colSecondPilon]);
            Foundation::Position pos = std::make_pair(indexLine, colFirstPilon);
            m_board[indexLine][colFirstPilon] = new Bridge(pilons, activePlayer, pos);
        }

    if (rowFirstPilon - rowSecondPilon == -2)
        for (uint8_t indexLine = rowSecondPilon; indexLine > rowFirstPilon; indexLine--)
        {
            Bridge::Pilons pilons = std::make_pair(m_board[rowFirstPilon][colFirstPilon], m_board[rowSecondPilon][colSecondPilon]);
            Foundation::Position pos = std::make_pair(indexLine, colFirstPilon);
            m_board[indexLine][colFirstPilon] = new Bridge(pilons, activePlayer, pos);
        }

    if (colFirstPilon - colSecondPilon == 2)
        for (uint8_t indexCol = colSecondPilon; indexCol < colFirstPilon; indexCol++)
        {
            Bridge::Pilons pilons = std::make_pair(m_board[rowFirstPilon][colFirstPilon], m_board[rowSecondPilon][colSecondPilon]);
            Foundation::Position pos = std::make_pair(rowFirstPilon, indexCol);
            m_board[rowFirstPilon][indexCol] = new Bridge(pilons, activePlayer, pos); // s-ar putea sa fie gresit
        }

    if (colFirstPilon - colSecondPilon == -2)
        for (uint8_t indexCol = colSecondPilon; indexCol > colFirstPilon; indexCol--)
        {
            Bridge::Pilons pilons = std::make_pair(m_board[rowFirstPilon][colFirstPilon], m_board[rowSecondPilon][colSecondPilon]);
            Foundation::Position pos = std::make_pair(rowFirstPilon, indexCol);
            m_board[rowFirstPilon][indexCol] = new Bridge(pilons, activePlayer, pos); // s-ar putea sa fie gresit
        }
}

const bool Board::IsInBoard(const Foundation::Position& pos) const
{
    auto [row, col] = pos;
    if (row >= 0 && row < m_size && col >= 0 && col < m_size && !IsCorner(pos))
        return true;
    return false;
}




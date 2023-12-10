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
            if (newX >= 0 && newX < m_size && newY >= 0 && newY < m_size && !visited[newX][newY] && IsBridge(m_board[newX][newY]))
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

const bool Board::IsCorner(const Pilon::Position& pos) const
{
    auto [row, col] = pos;
    if ((row == 0 && col == 0) ||
        (row == 0 && col == m_size - 1) ||
        (row == m_size - 1 && col == 0) ||
        (row == m_size - 1 && col == m_size - 1))
        return true;
    return false;
}

void Board::PrintCell(Pilon::Position pos, HANDLE &hConsole) const
{
    auto [row, col] = pos;
    if (IsCorner(pos))
    {
        std::cout << "  ";
        return;
    }
    if (IsRedBase(pos))
        SetConsoleTextAttribute(hConsole, 12);
    else if (IsBlueBase(pos))
        SetConsoleTextAttribute(hConsole, 9);
    else if (IsPiece(m_board[row][col]))
    {
        switch (m_board[row][col]->GetColor())
        {
        case Foundation::PlayerColor::Red:
            SetConsoleTextAttribute(hConsole, 12);
            break;
        case Foundation::PlayerColor::Black:
            SetConsoleTextAttribute(hConsole, 9);
            break;
        }
    }
    else
        SetConsoleTextAttribute(hConsole, 15);
    

    if (IsPilon(m_board[row][col]))
        std::cout << "P ";
    else if (IsBridge(m_board[row][col]))
        std::cout << "B ";
    else
        std::cout << ". ";
}

void Board::Reset()
{
    // sterge orice date existente pe tabla
    for (int i = 0; i < m_size; ++i) {
        for (int j = 0; j < m_size; ++j) {

            delete m_board[i][j]; // Resetarea celulelor la starea initiala.
        }
    }
}

//void Board::PlacePilon(const Pilon::Position& posPilon, const Foundation::PlayerColor& activePlayer)
//{
//    auto& [row, col] = posPilon;
//
//    if (IsInBoard(posPilon) && IsPilon(m_board[row][col]))
//        return;
//
//    delete m_board[row][col];
//
//    m_board[row][col] = new Pilon(activePlayer, posPilon);
//
//    std::vector<Pilon::Position> positions = AdjacentPilons(posPilon, activePlayer);
//    for (int index = 0; index < positions.size(); index++)
//        PlaceBridge(posPilon, positions[index], activePlayer);
//}

bool Board::PlacePilon(const Pilon::Position& posPilon, const Foundation::PlayerColor& activePlayer)
{
    auto& [row, col] = posPilon;

    if (!IsInBoard(posPilon))
        return false;

    if (IsPilon(m_board[row][col]))
        return false;

    delete m_board[row][col];

    m_board[row][col] = new Pilon(activePlayer, posPilon);

    std::vector<Pilon::Position> positions = AdjacentPilons(posPilon, activePlayer);
    for (int index = 0; index < positions.size(); index++)
        PlaceBridge(posPilon, positions[index], activePlayer);
    
    return true;
}

void Board::PlaceBridge(const Pilon::Position& posFirstPilon, const Pilon::Position& posSecondPilon, const Foundation::PlayerColor& activePlayer)
{
    auto& [rowFirstPilon, colFirstPilon] = posFirstPilon;
    auto& [rowSecondPilon, colSecondPilon] = posSecondPilon;

    if (rowFirstPilon - rowSecondPilon == 2)
        for (uint8_t indexLine = rowSecondPilon; indexLine < rowFirstPilon; indexLine++)
        {
            Bridge::Pilons pilons = std::make_pair(m_board[rowFirstPilon][colFirstPilon], m_board[rowSecondPilon][colSecondPilon]);
            m_board[indexLine][colFirstPilon] = new Bridge(pilons, activePlayer);
        }

    if (rowFirstPilon - rowSecondPilon == -2)
        for (uint8_t indexLine = rowSecondPilon; indexLine > rowFirstPilon; indexLine--)
        {
            Bridge::Pilons pilons = std::make_pair(m_board[rowFirstPilon][colFirstPilon], m_board[rowSecondPilon][colSecondPilon]);
            m_board[indexLine][colFirstPilon] = new Bridge(pilons, activePlayer);
        }

    if (colFirstPilon - colSecondPilon == 2)
        for (uint8_t indexCol = colSecondPilon; indexCol < colFirstPilon; indexCol++)
        {
            Bridge::Pilons pilons = std::make_pair(m_board[rowFirstPilon][colFirstPilon], m_board[rowSecondPilon][colSecondPilon]);
            m_board[rowFirstPilon][indexCol] = new Bridge(pilons, activePlayer); // s-ar putea sa fie gresit
        }

    if (colFirstPilon - colSecondPilon == -2)
        for (uint8_t indexCol = colSecondPilon; indexCol > colFirstPilon; indexCol--)
        {
            Bridge::Pilons pilons = std::make_pair(m_board[rowFirstPilon][colFirstPilon], m_board[rowSecondPilon][colSecondPilon]);
            m_board[rowFirstPilon][indexCol] = new Bridge(pilons, activePlayer); // s-ar putea sa fie gresit
        }
}

const bool Board::IsInBoard(const Pilon::Position& pos) const
{
    auto [row, col] = pos;
    if (row >= 0 && row < m_size && col >= 0 && col < m_size && !IsCorner(pos))
        return true;
    return false;
}

void Board::SetBoardSize(const int& size)
{
    m_size = size;
}

int Board::GetBoardSize() const
{
    return m_size;
}

bool Board::IsPilon(Foundation* f) const
{
    Pilon* p = dynamic_cast<Pilon*>(f);
    if (p)
        return true;
    return false;
}

bool Board::IsBridge(Foundation* f) const
{
    Bridge* b = dynamic_cast<Bridge*>(f);
    if (b)
        return true;
    return false;
}

bool Board::IsPiece(Foundation* f) const
{
    if (IsPilon(f) || IsBridge(f))
        return true;
    return false;
}

bool Board::IsRedBase(Pilon::Position pos) const
{
    auto& [row, col] = pos;
    if (row == 0 || row == m_size - 1)
        return true;
    return false;
}

bool Board::IsBlueBase(Pilon::Position pos) const
{
    auto& [row, col] = pos;
    if (col == 0 || col == m_size - 1)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& out, const Board& b)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    std::vector<std::vector<Foundation*>> board = b.GetBoard();
    size_t size = b.GetBoardSize();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            Pilon::Position pos = std::make_pair(i, j);
            b.PrintCell(pos, hConsole);//schimba cu Pilon::Position
        }
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 15);

    return out;
}

std::vector<Pilon::Position> Board::AdjacentPilons(const Pilon::Position& currentPos, const Foundation::PlayerColor& activePlayer)
{
    std::vector<Pilon::Position> positions;
    int rowVect[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
    int colVect[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    for (int index = 0; index < 8; index++)
    {
        if (Pilon::Position cellPos = std::make_pair(rowVect[index], colVect[index]); IsInBoard(cellPos) == true)
        {
            Pilon* p = dynamic_cast<Pilon*> (m_board[rowVect[index]][colVect[index]]);
            if (p && p->GetColor() == activePlayer)
                positions.push_back({ rowVect[index], colVect[index] });
        }
    }

    return positions;
}

bool Board::RemovePilon(const Pilon::Position& posPilon, const Foundation::PlayerColor& activePlayer)
{
    auto& [row, col] = posPilon;
    if (IsInBoard(posPilon))
    {
        if (IsPilon(m_board[row][col]) && m_board[row][col]->GetColor() == activePlayer)
        {
            delete m_board[row][col];
            m_board[row][col] = nullptr;
            return true;
        }
        else
            return false;
    }
    return false;
}
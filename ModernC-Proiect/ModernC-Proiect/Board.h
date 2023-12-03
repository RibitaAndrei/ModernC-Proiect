#pragma once
#include"Foundation.h"
#include "Pilon.h"
#include "Bridge.h"
#include <iostream>
#include <fstream>
#include <iosfwd>
#include <vector>
#include <cstdint>
#include <Windows.h>

class Board {
public:
    Board(int size);
    Board(const Board& copy);
    Board& operator=(const Board& copy) = default;
    ~Board() = default;

    //void SetCell(int row, int col, const Foundation& value);
    void SetBoardSize(const int& size);
    int GetBoardSize() const;
    void Reset();

    Foundation* GetCell(const int& row, const int& col) const;
    std::vector<std::vector<Foundation*>> GetBoard()const;

    const bool IsInBoard(const Foundation::Position& pos) const;
    const bool IsCorner(const Foundation::Position& pos) const;
    std::vector<Foundation::Position> AdjacentPilons(const Foundation::Position& currentPos, const Foundation::PlayerColor& activePlayer);
    void PlacePilon(const Foundation::Position& posPilon, const Foundation::PlayerColor& activePlayer);
    void RemovePilon(const Foundation::Position& posPilon);
    void PlaceBridge(const Foundation::Position& posFirstPilon, const Foundation::Position& posSecondPilon, const Foundation::PlayerColor& activePlayer);
    bool HasConnection() const;

    bool IsPilon(Foundation* f) const;
    bool IsBridge(Foundation* f) const;
    bool IsPiece(Foundation* f) const;
    bool IsRedBase(Foundation::Position pos) const;
    bool IsBlueBase(Foundation::Position pos) const;

    void PrintCell(Foundation::Position pos, HANDLE& hConsole) const;

    

    friend std::ostream& operator<< (std::ostream& out, const Board& b);
protected:
    int m_size;
    std::vector<std::vector<Foundation*>> m_board;
};
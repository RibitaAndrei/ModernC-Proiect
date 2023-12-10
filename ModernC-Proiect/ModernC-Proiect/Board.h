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

    const bool IsInBoard(const Pilon::Position& pos) const;
    const bool IsCorner(const Pilon::Position& pos) const;
    std::vector<Pilon::Position> AdjacentPilons(const Pilon::Position& currentPos, const Foundation::PlayerColor& activePlayer);
    void PlacePilon(const Pilon::Position& posPilon, const Foundation::PlayerColor& activePlayer);
    void PlacePilon(const Pilon::Position& posPilon, const Foundation::PlayerColor& activePlayer, bool& correctMove);
    void RemovePilon(const Pilon::Position& posPilon);
    void PlaceBridge(const Pilon::Position& posFirstPilon, const Pilon::Position& posSecondPilon, const Foundation::PlayerColor& activePlayer);
    bool HasConnection() const;

    bool IsPilon(Foundation* f) const;
    bool IsBridge(Foundation* f) const;
    bool IsPiece(Foundation* f) const;
    bool IsRedBase(Pilon::Position pos) const;
    bool IsBlueBase(Pilon::Position pos) const;

    void PrintCell(Pilon::Position pos, HANDLE& hConsole) const;

    

    friend std::ostream& operator<< (std::ostream& out, const Board& b);
protected:
    int m_size;
    std::vector<std::vector<Foundation*>> m_board;
};
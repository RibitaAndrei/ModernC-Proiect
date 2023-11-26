#pragma once
#include"Foundation.h"
#include "Pilon.h"
#include "Bridge.h"
#include "Enums.h"
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

    //void Initialize();
    void Display() const;
    //void SetCell(int row, int col, const Foundation& value);
    void SetBoardSize(const int& size);//facut de mine
    int GetBoardSize() const;//facut de mine
    void Reset();

    Foundation* GetCell(const int& row, const int& col) const;
    std::vector<std::vector<Foundation*>> GetBoard()const;

    const bool IsInBoard(const Foundation::Position& pos) const;
    const bool IsCorner(const Foundation::Position& pos) const;
    std::vector<Foundation::Position> AdjacentPilons(const Foundation::Position& currentPos, const Foundation::PlayerColor& activePlayer);
    void PlacePilon(const Foundation::Position& posPilon, const Foundation::PlayerColor& activePlayer);
    void PlaceBridge(const Foundation::Position& posFirstPilon, const Foundation::Position& posSecondPilon, const Foundation::PlayerColor& activePlayer);
    bool IsValidPilonPlacement(uint8_t xFoundation, uint8_t yFoundation);
    bool HasConnection() const;

    bool IsPilon(Foundation* f) const;
    bool IsBridge(Foundation* f) const;
    bool IsPiece(Foundation* f) const;
    bool IsRedBase(Foundation* f) const;
    bool IsBlueBase(Foundation* f) const;

    void PrintCell(Foundation* f, HANDLE& hConsole) const;

    friend std::ostream& operator<< (std::ostream& out, const Board& b);
protected:
    int m_size;
    std::vector<std::vector<Foundation*>> m_board;
};
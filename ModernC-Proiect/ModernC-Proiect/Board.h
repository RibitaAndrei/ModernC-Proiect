#pragma once
#include"Foundation.h"
#include <vector>
#include <Windows.h>
#include <cstdint>

class Board {
public:
    Board(int size);
    Board(const Board& copy);
    Board& operator=(const Board& copy) = default;
    ~Board() = default;

    //void Initialize();
    bool IsCorner(const int &row, const int &col) const;
    void PrintCell(const Foundation& cell, HANDLE hConsole) const;
    void Display() const;
    void SetCell(int row, int col, const Foundation& value);
    void ResetBoard();
    
    Foundation GetCell(int row, int col) const;
    std::vector<std::vector<Foundation>> GetBoard();

    void PlacePilon(uint16_t xFoundation, uint16_t yFoundation, int currentPlayer);
    void PlaceBridge(uint16_t xFoundation1, uint16_t yFoundation1, uint16_t xFoundation2, uint16_t yFoundation2, Foundation::Color color);
    bool IsInBoard(const int& row, const int& col) const;
    bool IsValidPilonPlacement(uint8_t xFoundation, uint8_t yFoundation);

    bool IsCellOccupied(const std::pair<int, int>& coordonate) const;

    bool HasConnection() const;
private:
    int m_size;
    std::vector<std::vector<Foundation>> m_board;
};
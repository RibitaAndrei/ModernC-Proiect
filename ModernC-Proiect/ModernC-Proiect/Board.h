#pragma once
#include"Foundation.h"
#include <vector>
#include <cstdint>

class Board {
public:
    Board(int size);
    Board(const Board& copy);
    Board& operator=(const Board& copy) = default;
    ~Board() = default;

    //void Initialize();
    void Display() const;
    void SetCell(int row, int col, const Foundation& value);
    void Reset();
    
    Foundation GetCell(int row, int col) const;
    std::vector<std::vector<Foundation>> GetBoard();

    void PlacePilon(uint16_t xFoundation, uint16_t yFoundation);
    void FillBridge(uint16_t xFoundation1, uint16_t yFoundation1, uint16_t xFoundation2, uint16_t yFoundation2);
    void PlaceBridge(uint16_t xFoundation1, uint16_t yFoundation1, uint16_t xFoundation2, uint16_t yFoundation2);
    bool IsValidPilonPlacement(uint8_t xFoundation, uint8_t yFoundation);
    bool HasConnection() const;
private:
    int m_size;
    std::vector<std::vector<Foundation>> m_board;
};
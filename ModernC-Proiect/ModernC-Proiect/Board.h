#pragma once
#include"Foundation.h"
#include <vector>
#include <cstdint>

class Board {
public:
    Board(int size);
    Board(const Board& copy);
    ~Board() = default;

    //void Initialize();
    void Display() const;
    void SetCell(int row, int col, const Foundation& value);
    void Reset();
    
    Foundation getCell(int row, int col) const;
    std::vector<std::vector<Foundation>> GetBoard();

    void PlacePilon(uint8_t xFoundation, uint8_t yFoundation);
    void FillBridge(uint8_t xFoundation1, uint8_t yFoundation1, uint8_t xFoundation2, uint8_t yFoundation2);
    void PlaceBridge(uint8_t xFoundation1, uint8_t yFoundation1, uint8_t xFoundation2, uint8_t yFoundation2);
private:
    int m_size;
    std::vector<std::vector<Foundation>> m_board;
};
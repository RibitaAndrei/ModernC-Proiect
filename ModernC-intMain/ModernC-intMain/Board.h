#pragma once
#include"IPiece.h"
#include "Pilon.h"
#include "Bridge.h"
#include "Player.h"
#include <iostream>
#include <fstream>
#include <iosfwd>
#include <vector>
#include <cstdint>
#include <Windows.h>
#include <array>

class Board {
public:
	Board();
	Board(uint16_t size);
	Board(const Board& copy);
	Board& operator=(const Board& copy) = default;
	~Board() = default;

	//void SetCell(int row, int col, const IPiece& value);
	void SetBoardSize(const uint16_t& size);
	uint16_t GetBoardSize() const;
	void Reset();

	IPiece* GetCell(const int& row, const int& col) const;
	std::vector<std::vector<IPiece*>> GetBoard()const;

	const bool IsInBoard(const Pilon::Position& pos) const;
	const bool IsCorner(const Pilon::Position& pos) const;
	std::vector<IPiece*> AdjacentPilons(const Pilon::Position& currentPos, Player* activePlayer);
	//void PlacePilon(const Pilon::Position& posPilon, const IPiece::PlayerColor& activePlayer);
	bool PlacePilon(const Pilon::Position& posPilon, Player* activePlayer);
	bool RemovePilon(const Pilon::Position& posPilon, const IPiece::PlayerColor& activePlayer);
	void PlaceBridge(IPiece* firstPilon, IPiece* secondPilon, Player* activePlayer);
	bool HasConnection() const;

	bool IsPilon(const Pilon::Position& pos) const; //modificat 17.12
	bool IsBridge(IPiece* f) const;
	bool IsPiece(IPiece* f) const;
	bool IsRedBase(Pilon::Position pos) const;
	bool IsBlueBase(Pilon::Position pos) const;

	std::vector<IPiece*> GetBridges() const;

	IPiece::PlayerColor GetColor(const Pilon::Position& pos);

	void PrintCell(Pilon::Position pos, HANDLE& hConsole) const;



	friend std::ostream& operator<< (std::ostream& out, const Board& b);
protected:
	uint16_t m_size;
	std::vector<std::vector<IPiece*>> m_board;
	std::vector<IPiece*> m_allBridges;
};
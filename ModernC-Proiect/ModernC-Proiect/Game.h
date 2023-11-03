#pragma once
#include "Player.h"
#include "Board.h"
class Game
{
public:
	Game(int boardSize, std::string playerName1, std::string playerName2);
	Game(const Game& copy);
	~Game();

	void SetBoardSize(int size);
	void SetFirstPlayerName(std::string name);
	void SetSecondPlayerName(std::string name);
	
	int GetBoardSize();
	std::string GetFirstPlayerName();
	std::string GetSecondPlayerName();

private:
	Player m_player1, m_player2;
	Board m_gameBoard;
};


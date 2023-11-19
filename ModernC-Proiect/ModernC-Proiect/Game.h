#pragma once
#include "Player.h"
#include "Board.h"
#include <iostream>
class Game
{
public:
	Game(int boardSize);
	Game(int boardSize, std::string playerName1, std::string playerName2);
	Game& operator=(const Game& copy) = default;
	Game(const Game& copy);
	~Game();

	void SetBoardSize(int size);
	void SetFirstPlayerName(std::string name);
	void SetSecondPlayerName(std::string name);
	
	int GetBoardSize();
	std::string GetFirstPlayerName();
	std::string GetSecondPlayerName();

	void PauseMenu();

	bool PlacePiece(const std::pair<int, int>& coordinates);
	
	void DisplayRules() const;

	void StartGame();
	void StartRound();
	bool CheckWinCondition() const;

	void ResetGame();

private:
	Player m_player1, m_player2;
	Board m_gameBoard;

	bool m_gameFinished;

	void DisplayScore();
};


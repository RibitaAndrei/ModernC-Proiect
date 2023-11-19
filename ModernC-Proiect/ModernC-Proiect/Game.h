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

	int GetScorePlayer1() const;
	int GetScorePlayer2() const;

	void SetScorePlayer1(int score);
	void SetScorePlayer2(int score);

	void AddScorePlayer1();
	void AddScorePlayer2();

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

	int m_scorePlayer1;
	int m_scorePlayer2;

	bool m_gameFinished;

	void DisplayScore();
};


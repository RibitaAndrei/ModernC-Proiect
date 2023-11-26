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

	enum class ActivePlayer//nou
	{
		Player1,
		Player2
	};

	void SetBoardSize(int size);
	void SetFirstPlayerName(const std::string& name);
	void SetSecondPlayerName(const std::string& name);

	int GetBoardSize() const;
	std::string GetFirstPlayerName() const;
	std::string GetSecondPlayerName() const;

	int GetScorePlayer1() const;
	int GetScorePlayer2() const;

	void SetScorePlayer1(const int& score);
	void SetScorePlayer2(const int& score);

	void AddScorePlayer1();
	void AddScorePlayer2();

	bool PlacePiece(const std::pair<int, int>& coordinates);

	void StartGame();
	//bool CheckWinCondition() const;

	void ResetGame();

private:
	Player m_player1, m_player2;
	Board m_gameBoard;

	int m_scorePlayer1;
	int m_scorePlayer2;

	bool m_gameFinished;
	ActivePlayer m_activePlayer;//nou
};


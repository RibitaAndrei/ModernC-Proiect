#pragma once
#include "Player.h"
#include "Board.h"
#include "ScoreManager.h"
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

	void PauseMenu();

	// functie pentru inregistrarea miscarilor
	void RecordMove(const std::string& playerName, const Foundation::Position& coordinates);

	// functie pentru afisarea istoricului miscarilor
	void DisplayMoveHistory() const;

	bool PlacePiece(const std::pair<int, int>& coordinates);
	
	void DisplayRules() const;

	void SwapPlayers();

	void ReadPlayersAndBoard(std::string playerName, int& boardSize);
	void MainMenu();
	void StartGame();
	void DisplayGame();
	bool CheckWinCondition() const;

	void ActionPlayer1();
	void ActionPlayer2();


	void ResetGame();

private:
	Player m_player1, m_player2;
	Board m_gameBoard;

	int m_scorePlayer1;
	int m_scorePlayer2;
	ActivePlayer m_activePlayer;//nou

	bool m_gameFinished;

	// structura pentru a stoca o miscare
	struct Move {
		std::string playerName;
		Foundation::Position coordinates;

		Move(const std::string& name, const Foundation::Position& pos)
			: playerName(name), coordinates(pos) {}
	};

	std::vector<Move> moveHistory; // vector pentru a stoca istoricul miscarilor


	void DisplayScore();
};


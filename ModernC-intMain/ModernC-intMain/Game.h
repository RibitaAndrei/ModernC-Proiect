#pragma once
#include "Player.h"
#include "Board.h"
#include "ScoreManager.h"
#include "Constants.h"
#include <iostream>

class Game
{
public:
	Game();
	Game(uint16_t boardSize);
	Game(uint16_t boardSize, std::string playerName1, std::string playerName2);
	Game& operator=(const Game& copy) = default;
	Game(const Game& copy);
	~Game();

	enum class ActivePlayer//nou
	{
		Player1,
		Player2
	};//cred totusi ca ar fi mai simplu fara acest enum
	// ca sa fie nevoie sa facem legatura intre enum-ul asta
	// si cel de culoare
	// las asa momentan totusi, mai vedem pe parcurs
	// ar fi o idee ca m_activePlayer sa fie un pointer catre o clasa Player
	// sa avem cate una pentru fiecare player

	Player* GetNextPlayer();
	Player* GetActivePlayer();
	void SetNextPlayer();

	bool IsPilon(const Pilon::Position& pos); //17.12

	IPiece::PlayerColor GetColor(const Pilon::Position& pos);

	void SetBoardSize(int size);
	bool IsCorner(const Pilon::Position& pos);

	int GetBoardSize() const;

	int GetScorePlayer1() const;
	int GetScorePlayer2() const;

	void SetScorePlayer1(const int& score);
	void SetScorePlayer2(const int& score);

	Player GetFirstPlayer() const;
	Player GetSecondPlayer() const;

	void AddScorePlayer1();
	void AddScorePlayer2();

	void PauseMenu();

	// functie pentru inregistrarea miscarilor
	void RecordMove(const std::string& playerName, const Pilon::Position& coordinates);

	// functie pentru afisarea istoricului miscarilor
	void DisplayMoveHistory() const;

	bool PlacePilon(const Pilon::Position& coordinates);

	void DisplayRules() const;

	void SwapPlayers();

	void ReadPlayersAndBoard(std::string playerName, int& boardSize);
	void MainMenu();
	//void StartGame();
	void DisplayGame();
	bool CheckWinCondition() const;

	std::vector<IPiece*> GetBridges() const;

	//void GetMove(Player currentPlayer, int turn);

	//void ActionPlayer1();
	//void ActionPlayer2();
	//void FirstTurn();

	//void ResetGame();

private:
	Player m_player1, m_player2;
	Player* m_activePlayer;
	Board m_gameBoard;
	int m_scorePlayer1;
	int m_scorePlayer2; //scorurile de pus in player
	bool m_gameFinished;

	// structura pentru a stoca o miscare
	struct Move {
		std::string playerName;
		Pilon::Position coordinates;

		Move(const std::string& name, const Pilon::Position& pos)
			: playerName(name), coordinates(pos) {}
	};

	std::vector<Move> moveHistory; // vector pentru a stoca istoricul miscarilor


	//void DisplayScore();
};
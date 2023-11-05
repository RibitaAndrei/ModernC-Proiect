#include "Game.h"
// Constructor cu parametri
Game::Game(int boardSize, std::string playerName1, std::string playerName2) :
    m_gameBoard(boardSize), m_player1(playerName1, 'r'), m_player2(playerName2, 'b')
{
}
// Constructor de copiere
Game::Game(const Game& copy) :
    m_gameBoard(copy.m_gameBoard), m_player1(copy.m_player1), m_player2(copy.m_player2)
{
}
// Destructor
Game::~Game()
{
}

// Setează dimensiunea tablei de joc
void Game::SetBoardSize(int size)
{
    m_gameBoard.Initialize(); // Inițializează tabla cu dimensiunea specificată
    m_gameBoard.Reset(); // Resetează tabla
}

// Setează numele primului jucător
void Game::SetFirstPlayerName(std::string name)
{
    m_player1.SetPlayerName(name);
}

// Setează numele celui de-al doilea jucător
void Game::SetSecondPlayerName(std::string name)
{
    m_player2.SetPlayerName(name);
}

// Obține dimensiunea tablei de joc
int Game::GetBoardSize()
{
    return m_gameBoard.GetBoard().size();
}

// Obține numele primului jucător
std::string Game::GetFirstPlayerName()
{
    return m_player1.GetPlayerName();
}

// Obține numele celui de-al doilea jucător
std::string Game::GetSecondPlayerName()
{
    return m_player2.GetPlayerName();
}
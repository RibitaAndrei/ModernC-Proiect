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
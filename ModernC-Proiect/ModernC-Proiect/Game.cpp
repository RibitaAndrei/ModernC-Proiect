#include "Game.h"
#include <conio.h>
#include <iostream>
Game::Game(int boardSize)
    :m_player1{ 'r' },
    m_player2{ 'b' },
    m_gameBoard{ 24 },
    m_scorePlayer1(0),
    m_scorePlayer2(0),
    m_gameFinished(false)
{
}
// Constructor cu parametri
Game::Game(int boardSize, std::string playerName1, std::string playerName2) :
    m_gameBoard(boardSize), m_player1(playerName1, 'r'), m_player2(playerName2, 'b'),
    m_scorePlayer1(0), m_scorePlayer2(0), m_gameFinished(false) // Inițializarea scorurilor la zero
{
}
// Constructor de copiere
Game::Game(const Game& copy) :
    m_gameBoard(copy.m_gameBoard), m_player1(copy.m_player1), m_player2(copy.m_player2), m_gameFinished(false)
{
}
// Destructor
Game::~Game()
{
}

// Setează dimensiunea tablei de joc
void Game::SetBoardSize(int size)
{
    
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

int Game::GetScorePlayer1() const
{
    return m_scorePlayer1;
}

int Game::GetScorePlayer2() const
{
    return m_scorePlayer2;
}

void Game::StartGame()
{
    int turn = 1;
    std::string playerName;
    std::cout << "Player 1, enter your name: ";
    std::cin >> playerName;
    m_player1.SetPlayerName(playerName);
    std::cout << "Player 2, enter your name: ";
    std::cin >> playerName;
    m_player1.SetPlayerName(playerName);
    
    while (!m_gameFinished)
    {
        system("CLS");
        m_gameBoard.Display();
        if (turn % 2 == 1)
            std::cout << m_player1.GetPlayerName() << " enter the type of piece you want to place (p/b): ";
        else 
            std::cout << m_player2.GetPlayerName() << " enter the type of piece you want to place (p/b): ";
        if (_getch() == 'p')
        {
            std::cout << std::endl << "Enter the coordinates of your pilon: ";
            std::pair <int, int> coordinates;
            std::cin >> coordinates.first >> coordinates.second;
        }
    }
}

bool Game::CheckWinCondition() const
{
    return m_gameBoard.HasConnection();
}

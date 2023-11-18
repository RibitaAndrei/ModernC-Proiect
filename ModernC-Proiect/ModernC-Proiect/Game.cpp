#include "Game.h"
#include "Pilon.h"
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

void Game::SetScorePlayer1(int score)
{
    m_scorePlayer1 = score;
}

void Game::SetScorePlayer2(int score)
{
    m_scorePlayer2 = score;
}

void Game::AddScorePlayer1()
{
    m_scorePlayer1++;
}

void Game::AddScorePlayer2()
{
    m_scorePlayer2++;
}

void Game::DisplayScore()
{
    system("CLS");
    std::cout << "----- Score -----" << std::endl;
    std::cout << m_player1.GetPlayerName() << ": " << GetScorePlayer1() << std::endl;
    std::cout << m_player2.GetPlayerName() << ": " << GetScorePlayer2() << std::endl;
    std::cout << "------------------" << std::endl;
}

void Game::PauseMenu()
{
    char choice;
    do
    {
        system("CLS");
        std::cout << "----- Pause Menu -----" << std::endl;
        std::cout << "1. Continue Game" << std::endl;
        std::cout << "2. Reset Game" << std::endl;
        std::cout << "3. Quit to Main Menu" << std::endl;
        std::cout << "Enter your choice (1-3): ";
        choice = _getch();
        switch (choice)
        {
        case '1':
            // Continue game
            break;

        case '2':
            // Reset game
            ResetGame();
            break;

        case '3':
            // Quit to main menu or exit the program
            m_gameFinished = true;
            break;

        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    } while (choice != '1' && choice != '3');
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
    m_player2.SetPlayerName(playerName);

    while (!m_gameFinished)
    {
        DisplayScore();
        system("CLS");
        m_gameBoard.Display();

        if (turn % 2 == 1)
        {
            std::cout << m_player1.GetPlayerName() << " enter the coordinates of your next pilon: ";
            uint16_t row, col;
            std::cin >> row >> col;
            m_gameBoard.PlacePilon(row, col);
        }
        else
        {
            std::cout << m_player2.GetPlayerName() << " enter the coordinates of your next pilon: ";
            uint16_t row, col;
            std::cin >> row >> col;
            m_gameBoard.PlacePilon(row, col);
        }

        turn++;
    }
}



bool Game::CheckWinCondition() const
{
    return m_gameBoard.HasConnection();
}

void Game::ResetGame()
{
    //Reset();
    SetScorePlayer1(0);
    SetScorePlayer2(0);
    m_player1.SetPilonCounter(50);
    m_player1.SetBridgeCounter(50);
    m_player2.SetPilonCounter(50);
    m_player2.SetBridgeCounter(50);
    StartGame();
}






#include "Game.h"
#include "Pilon.h"
#include <conio.h>
#include <iostream>

Game::Game(int boardSize)
    :m_player1{ 'r' },
    m_player2{ 'b' },
    m_gameBoard{ 24 },
    m_scorePlayer1{ 0 },
    m_scorePlayer2{ 0 },
    m_gameFinished{ false },
    m_activePlayer{ ActivePlayer::Player1 }
{
}
// Constructor cu parametri
Game::Game(int boardSize, std::string playerName1, std::string playerName2) :
    m_gameBoard{ boardSize }, m_player1{ playerName1, 'r' }, m_player2{ playerName2, 'b' }, m_gameFinished{ false } // Inițializarea scorurilor la zero
{
}
// Constructor de copiere
Game::Game(const Game& copy) :
    Game(copy.GetBoardSize(), copy.GetFirstPlayerName(), copy.GetSecondPlayerName())
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
void Game::SetFirstPlayerName(const std::string &name)
{
    m_player1.SetPlayerName(name);
}

// Setează numele celui de-al doilea jucător
void Game::SetSecondPlayerName(const std::string &name)
{
    m_player2.SetPlayerName(name);
}

// Obține dimensiunea tablei de joc
int Game::GetBoardSize() const
{
    return m_gameBoard.GetBoard().size();
}

// Obține numele primului jucător
std::string Game::GetFirstPlayerName() const
{
    return m_player1.GetPlayerName();
}

// Obține numele celui de-al doilea jucător
std::string Game::GetSecondPlayerName() const
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

void Game::SetScorePlayer1(const int& score)
{
    m_scorePlayer1 = score;
}

void Game::SetScorePlayer2(const int& score)
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

/*void Game::DisplayScore()
{
    system("CLS");
    std::cout << "----- Score -----" << std::endl;
    std::cout << m_player1.GetPlayerName() << ": " << GetScorePlayer1() << std::endl;
    std::cout << m_player2.GetPlayerName() << ": " << GetScorePlayer2() << std::endl;
    std::cout << "------------------" << std::endl;
}*/

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

void Game::DisplayRules() const
{
    system("CLS");
    std::cout << "----- Rules of Twixt -----" << std::endl;
    std::cout << "1. Players take turns placing pilons on the board." << std::endl;
    std::cout << "2. Pilons can be connected by building bridges between them." << std::endl;
    std::cout << "3. The goal is to create a continuous connection from one side of the board to the other." << std::endl;
    std::cout << "4. The player who first connects their sides wins the game." << std::endl;
    std::cout << "5. Each player has a limited number of pilons and bridges." << std::endl;
    std::cout << "6. Use strategic placement to block your opponent's connections." << std::endl;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Press any key to return to the main menu." << std::endl;
    _getch(); // Asteapta apasarea unei taste pentru a reveni la meniu
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

    char choice;
    do
    {
        system("CLS");
        std::cout << "----- Main Menu -----" << std::endl;
        std::cout << "1. Start Game" << std::endl;
        std::cout << "2. Display Rules" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Enter your choice (1-3): ";
        choice = _getch();
        switch (choice - '0')
        {
        case 1:
            // Start game
            while (!m_gameFinished)
            {
                system("CLS");
                std::cout << m_gameBoard;

                if (turn % 2 == 1)
                {
                    Foundation::Position coordinates;
                    auto& [row, col] = coordinates;
                    if (turn == 1)
                    {
                        std::cout << m_player1.GetPlayerName() << " enter the position of your first pilon (needs to be in base): ";
                        std::cin >> row >> col;
                        while (!m_gameBoard.IsRedBase(coordinates))
                        {
                            std::cout << "Try again: ";
                            std::cin >> row >> col;
                        }
                        m_gameBoard.PlacePilon(coordinates, Foundation::PlayerColor::Red);
                    }
                    else
                    {
                        std::cout << m_player1.GetPlayerName() << " enter the position of your next pilon: ";
                        std::cin >> row >> col;
                        m_gameBoard.PlacePilon(coordinates, Foundation::PlayerColor::Red);
                    }
                }
                else
                {
                    if (turn == 2)
                    {
                        std::cout << m_player2.GetPlayerName() << " press \'s\' to switch sides with your opponent, or \'p\' to place pilon:";
                        char getChoice = _getch();
                        if (getChoice == 's')
                        {
                            //implementati schimbarea de echipe aici
                            //ar putea fi doar interschimbarea numelor celor 2 jucatori
                        }
                        else{} // nu face nimic, jocul continua normal
                    }
                    std::cout << m_player2.GetPlayerName() << " enter the position of your next pilon: ";
                    Foundation::Position coordinates;
                    auto& [row, col] = coordinates;
                    std::cin >> row >> col;
                    m_gameBoard.PlacePilon(coordinates, Foundation::PlayerColor::Black);
                }
                turn++;
            }
            break;

        case 2:
            // Display rules
            DisplayRules();
            break;

        case 3:
            // Quit
            m_gameFinished = true;
            break;

        default:
            std::cout << "Invalid choice. Try again. Press any key to return to menu" << std::endl;
            _getch();
            break;
        }
    } while (choice != 3);
}

bool Game::CheckWinCondition() const
{
    return m_gameBoard.HasConnection();
}

void Game::ResetGame()
{
    //ResetBoard();
    StartGame();
}






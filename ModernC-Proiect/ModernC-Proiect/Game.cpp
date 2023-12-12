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

Game::ActivePlayer Game::nextPlayer()
{
    if (m_activePlayer == ActivePlayer::Player1)
        return ActivePlayer::Player2;
    else
        return ActivePlayer::Player1;
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
        std::cout << kPause << kContinue << kReset << kQuit << kPauseChoice;
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
            std::cout << kInvalidChoice;
            break;
        }
    } while (choice != '1' && choice != '3');
}

void Game::RecordMove(const std::string& playerName, const Pilon::Position& coordinates)
{
    moveHistory.emplace_back(playerName, coordinates);
}

void Game::DisplayMoveHistory() const
{
    system("CLS"); // curata ecranul pentru a afisa istoricul miscarilor

    std::cout << "----- Move History -----" << std::endl;
    for (const auto& move : moveHistory) {
        std::cout << move.playerName << " moved to position (" << move.coordinates.first << ", " << move.coordinates.second << ")" << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    std::cout << "Press any key to return to the main menu." << std::endl;
    _getch(); // asteapta apasarea unei taste pentru a reveni la meniu
}

void Game::DisplayRules() const
{
    system("CLS");
    std::cout << "----- Rules of Twixt -----" << std::endl;
    std::cout << kRule1 << kRule2 << kRule3 << kRule4 << kRule5 << kRule6;
    std::cout << "---------------------------" << std::endl;
    std::cout << "Press any key to return to the main menu." << std::endl;
    _getch(); // Asteapta apasarea unei taste pentru a reveni la meniu
}

void Game::SwapPlayers() // nu vrea std::swap-ul sa mearga
{
    std::string temp = m_player1.GetPlayerName();
    m_player1.SetPlayerName(m_player2.GetPlayerName());
    m_player2.SetPlayerName(temp);
}

void Game::ReadPlayersAndBoard(std::string playerName, int& boardSize)
{	

	std::cout << kPlayer1Choice;
	std::cin >> playerName;
	m_player1.SetPlayerName(playerName);

	std::cout << kPlayer2Choice;
	std::cin >> playerName;
	m_player2.SetPlayerName(playerName);

	std::cout << kBoardChoice;
	std::cin >> boardSize;
	m_gameBoard.SetBoardSize(boardSize);
}

void Game::MainMenu()
{
	system("CLS");
	std::cout << "----- Main Menu -----" << std::endl;
	std::cout << "1. Start Game" << std::endl;
	std::cout << "2. Display Rules" << std::endl;
	std::cout << "3. Quit" << std::endl;
	std::cout << "Enter your choice (1-3): ";
}

void Game::DisplayGame()
{
    system("CLS");
    std::cout << "Player 1: " << m_player1.GetPlayerName() << '\n';
    std::cout << "Player 2: " << m_player2.GetPlayerName() << '\n';
    std::cout << "Score: " << '\n';
    std::cout << m_gameBoard;
}

void Game::StartGame()
{
    int turn = 1;
	int boardSize;
	std::string playerName;
    ReadPlayersAndBoard(playerName, boardSize);

    char choice;
    do
    {
        MainMenu();
        choice = _getch();
        switch (choice - '0')
        {
        case 1:
            // Start game
            while (!m_gameFinished)
            {
                DisplayGame();
                if (m_activePlayer == ActivePlayer::Player1)
                {
                    
                    if (turn == 1)
                    {
                        FirstTurn();
                    }
                    else
                    {
                        ActionPlayer1();
                    }
                }
                else
                {
                    if (turn == 2)
                    {
                        FirstTurn();
                    }
                    else
                    {
                        ActionPlayer2();
                    }
                }
                turn++;
            }
            break;

        case 2:
            // Display rules
            DisplayRules();
            break;

        case 3:
            // Pause Game
            PauseMenu();
            break;

        case 4:
            // Quit
            m_gameFinished = true;
            break;

        default:
            std::cout << kInvalidChoice << std::endl;
            _getch();
            break;
        }
    } while (choice != 4);
}

void Game::ActionPlayer1()
{
    Pilon::Position coordinates;
    auto& [row, col] = coordinates;
    bool correctMove = false;
    std::cout << m_player1.GetPlayerName() << kActionChoice;
    char option = _getch();
    switch (option - '0')
    {
    case 1:
        std::cout << m_player1.GetPlayerName() << kPlacePilon;
        std::cin >> row >> col;
        correctMove = m_gameBoard.PlacePilon(coordinates, Foundation::PlayerColor::Red);
        while (!correctMove)
        {
            DisplayGame();
            std::cout << kIncorrectMove;
            std::cout << m_player1.GetPlayerName() << kPlacePilon;
            std::cin >> row >> col;
            correctMove = m_gameBoard.PlacePilon(coordinates, Foundation::PlayerColor::Red);
        }
        break;
    case 2:
        std::cout << m_player1.GetPlayerName() << kRemovePilon;
        std::cin >> row >> col;
        correctMove = m_gameBoard.RemovePilon(coordinates, Foundation::PlayerColor::Red);
        while (!correctMove)
        {
            DisplayGame();
            std::cout << kIncorrectMove;
            std::cout << m_player1.GetPlayerName() << kRemovePilon;
            std::cin >> row >> col;
            correctMove = m_gameBoard.RemovePilon(coordinates, Foundation::PlayerColor::Red);
        }
        break;
    default:
        break;
    }

    m_activePlayer = nextPlayer();
}

void Game::ActionPlayer2()
{
    Pilon::Position coordinates;
    auto& [row, col] = coordinates;
    bool correctMove = false;
    std::cout << m_player2.GetPlayerName() << kActionChoice << '\n';
    char option = _getch();
    switch (option - '0')
    {
    case 1:
        
        std::cout << m_player2.GetPlayerName() << kPlacePilon;
        std::cin >> row >> col;
        correctMove = m_gameBoard.PlacePilon(coordinates, Foundation::PlayerColor::Black);
        while (!correctMove)
        {
            DisplayGame();
            std::cout << kIncorrectMove;
            std::cout << m_player2.GetPlayerName() << kPlacePilon;
            std::cin >> row >> col;
            correctMove = m_gameBoard.PlacePilon(coordinates, Foundation::PlayerColor::Black);
        }
        break;
    case 2:
        std::cout << m_player2.GetPlayerName() << kRemovePilon;
        std::cin >> row >> col;
        correctMove = m_gameBoard.RemovePilon(coordinates, Foundation::PlayerColor::Black);
        while (!correctMove)
        {
            DisplayGame();
            std::cout << kIncorrectMove;
            std::cout << m_player2.GetPlayerName() << kRemovePilon;
            std::cin >> row >> col;
            correctMove = m_gameBoard.RemovePilon(coordinates, Foundation::PlayerColor::Black);
        }
        break;
    default:
        break;
    }

    m_activePlayer = nextPlayer();
}

void Game::FirstTurn()
{
    Pilon::Position coordinates;
    auto& [row, col] = coordinates;

    if (m_activePlayer == ActivePlayer::Player2)
    {
        std::cout << m_player2.GetPlayerName() << kSwitchOption;
        char getChoice = _getch();
        if (getChoice == 's')
        {
            SwapPlayers();
            DisplayGame();
        }
        else {
            std::cout << m_player2.GetPlayerName() << kFirstAction;
            std::cin >> row >> col;
            while (!m_gameBoard.IsBlueBase(coordinates))
            {
                std::cout << "Try again: ";
                std::cin >> row >> col;
            }
            m_gameBoard.PlacePilon(coordinates, Foundation::PlayerColor::Black);
            // daca m_activePlayer ar fi un pointer catre un Player
            // codu asta s-ar generaliza pentru ambii playeri
            // nu s-ar mai repeta mai jos
        }
    }
    else
    {
        std::cout << m_player1.GetPlayerName() << kFirstAction;
        std::cin >> row >> col;
        while (!m_gameBoard.IsRedBase(coordinates))
        {
            std::cout << "Try again: ";
            std::cin >> row >> col;
        }
        m_gameBoard.PlacePilon(coordinates, Foundation::PlayerColor::Red);
    }

    m_activePlayer = nextPlayer();
}

bool Game::CheckWinCondition() const
{
    return m_gameBoard.HasConnection();
}

//void Game::GetMove(Player currentPlayer, int turn)
//{
//
//}

void Game::ResetGame()
{
    //ResetBoard();
    StartGame();
}
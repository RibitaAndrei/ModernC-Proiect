#include "mainwindow.h"

mainwindow::mainwindow(QWidget* parent, const int& boardSize)
    : QMainWindow(parent),
    m_windowHeight{ 2 * kVerticalMarginSize + boardSize * kSquareSize },
    m_windowWidth{ 2 * kHorizontalMarginSize + boardSize * kSquareSize },
    m_boardSizeRects{ boardSize },
    m_boardSizePixels{ m_boardSizeRects * kSquareSize }
{
    m_game.SetBoardSize(boardSize);
    this->setFixedSize(m_windowWidth, m_windowHeight);
    ui.setupUi(this);

}

mainwindow::~mainwindow()
{}

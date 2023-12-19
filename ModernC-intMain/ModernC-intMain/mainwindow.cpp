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

void mainwindow::mouseReleaseEvent(QMouseEvent* e)
{
    if (e->button() == Qt::LeftButton)
    {
        int rowRect{ (e->x() - kHorizontalMarginSize) / m_boardSizeRects };
        int colRect{ (e->y() - kVerticalMarginSize) / m_boardSizeRects };
        Pilon::Position rectPos{ std::make_pair(rowRect, colRect) };
		if (rowRect > 0 && colRect > 0 && !m_game.IsCorner(rectPos))
		{
			QRect foundation{ kHorizontalMarginSize + kSquareSize * colRect, kVerticalMarginSize + kSquareSize * rowRect, kSquareSize, kSquareSize };
			if (fabs(foundation.center().x() - e->pos().x()) < kFoundationRadius &&
				fabs(foundation.center().y() - e->pos().y()) < kFoundationRadius)
			{
				//make foundation a red/blue pilon
				Pilon::Position pos{ std::make_pair(rowRect, colRect) };
				m_game.PlacePilon(pos);
				update();
			}
		}
    }
}

void mainwindow::paintEvent(QPaintEvent* e)
{
	QPainter painter(this);
	QPen pen;
	painter.setPen(pen);

	for (int indexRow = 0; indexRow < m_boardSizeRects; ++indexRow)
	{
		for (int indexCol = 0; indexCol < m_boardSizeRects; ++indexCol)
		{
			//de adaugat verificarea daca este un pilon pe pozitia curenta
			//si de adaugat afisarea pilonului pe tabla
			Pilon::Position foundationCoords = std::make_pair(indexRow, indexCol);
			if (!m_game.IsCorner(foundationCoords))
			{
				std::pair<int, int> foundationCenter;
				foundationCenter.first = kHorizontalMarginSize + kSquareSize * indexCol + kSquareSize / 2;
				foundationCenter.second = kVerticalMarginSize + kSquareSize * indexRow + kSquareSize / 2;
				QPoint center(foundationCenter.first, foundationCenter.second);
				QRect foundation{ kHorizontalMarginSize + kSquareSize * indexCol, kVerticalMarginSize + kSquareSize * indexRow, kSquareSize, kSquareSize };
				painter.drawEllipse(center, kFoundationRadius, kFoundationRadius);

				if (m_game.IsPilon(std::make_pair(indexRow, indexCol)))
				{
					if (m_game.GetColor(std::make_pair(indexRow, indexCol)) == Foundation::PlayerColor::Red)
						painter.fillRect(foundation, Qt::red);
					else
						painter.fillRect(foundation, Qt::blue);
				}
			}

		}

	}
}

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

void DrawProperLine(QPoint& firstNode, QPoint& secondNode, int foundationSize)
{
	double angle{ atan2(secondNode.y() - firstNode.y(), secondNode.x() - firstNode.x()) };
	double offsetX{ cos(angle) * foundationSize };
	double offsetY{ sin(angle) * foundationSize };

	firstNode.setX(firstNode.x() + offsetX);
	firstNode.setY(firstNode.y() + offsetY);

	secondNode.setX(secondNode.x() - offsetX);
	secondNode.setY(secondNode.y() - offsetY);
}

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
			Pilon::Position foundationCoords = std::make_pair(indexRow, indexCol);
			if (!m_game.IsCorner(foundationCoords))
			{
				std::pair<int, int> foundationCenter;
				foundationCenter.first = kHorizontalMarginSize + kSquareSize * indexCol + kSquareSize / 2;
				foundationCenter.second = kVerticalMarginSize + kSquareSize * indexRow + kSquareSize / 2;
				QPoint center(foundationCenter.first, foundationCenter.second);
				QRect foundation{ kHorizontalMarginSize + kSquareSize * indexCol, kVerticalMarginSize + kSquareSize * indexRow, kSquareSize, kSquareSize };
				if (m_game.IsPilon(std::make_pair(indexRow, indexCol)))
				{
					if (m_game.GetColor(std::make_pair(indexRow, indexCol)) == IPiece::PlayerColor::Red)
					{
						painter.setBrush(Qt::red);
						painter.drawEllipse(center, kFoundationRadius, kFoundationRadius);
					}
					else
					{
						painter.setBrush(Qt::blue);
						painter.drawEllipse(center, kFoundationRadius, kFoundationRadius);
					}
				}
				else
				{
					painter.setBrush(Qt::white);
					painter.drawEllipse(center, kFoundationRadius, kFoundationRadius);
				}
			}
		}
	}

	std::vector<IPiece*> bridges = m_game.GetBridges();
	for (auto& bridge : bridges)
	{
		Bridge* b = dynamic_cast<Bridge*>(bridge);
		Pilon* first = dynamic_cast<Pilon*>(b->GetFirstPilon());
		Pilon* second = dynamic_cast<Pilon*>(b->GetSecondPilon());

		uint16_t row = kVerticalMarginSize + kSquareSize * first->GetRow() + kSquareSize / 2;
		uint16_t col = kHorizontalMarginSize + kSquareSize * first->GetColumn() + kSquareSize / 2;
		QPoint firstCenter{ col, row };

		row = kVerticalMarginSize + kSquareSize * second->GetRow() + kSquareSize / 2;
		col = kHorizontalMarginSize + kSquareSize * second->GetColumn() + kSquareSize / 2;
		QPoint secondCenter{ col, row };

		DrawProperLine(firstCenter, secondCenter, kFoundationRadius);
		pen.setWidth(2);
		painter.setPen(pen);
		painter.drawLine(firstCenter, secondCenter);
	}

	QPoint topLeftCorner(kHorizontalMarginSize + kSquareSize, kVerticalMarginSize + kSquareSize);
	QPoint topRightCorner(kHorizontalMarginSize + kSquareSize * (m_boardSizeRects - 1), kVerticalMarginSize + kSquareSize);
	QPoint bottomLeftCorner(kHorizontalMarginSize + kSquareSize, kVerticalMarginSize + kSquareSize * (m_boardSizeRects - 1));
	QPoint bottomRightCorner(kHorizontalMarginSize + kSquareSize * (m_boardSizeRects - 1), kVerticalMarginSize + kSquareSize * (m_boardSizeRects - 1));

	QLine redBaseLineLeft(topLeftCorner, bottomLeftCorner);
	QLine redBaseLineRight(topRightCorner, bottomRightCorner);
	QLine blueBaseLineTop(topLeftCorner, topRightCorner);
	QLine blueBaseLineBottom(bottomLeftCorner, bottomRightCorner);

	pen.setWidth(2);

	pen.setColor(Qt::black);
	painter.setPen(pen);
	painter.drawLine(redBaseLineLeft);
	painter.drawLine(redBaseLineRight);

	pen.setColor(Qt::red);
	painter.setPen(pen);
	painter.drawLine(blueBaseLineTop);
	painter.drawLine(blueBaseLineBottom);


}

void mainwindow::SetLabelNames()
{
	player1.setText("Player 1");
	player2.setText("Player 2");
	firstName.setText(QString::fromStdString(m_game.GetFirstPlayer().GetPlayerName()));
	secondName.setText(QString::fromStdString(m_game.GetSecondPlayer().GetPlayerName()));
	firstPilons.setText(QString::number(m_game.GetFirstPlayer().GetPilonCounter()));
	secondPilons.setText(QString::number(m_game.GetSecondPlayer().GetPilonCounter()));
	firstBridges.setText(QString::number(m_game.GetFirstPlayer().GetBridgeCounter()));
	secondBridges.setText(QString::number(m_game.GetSecondPlayer().GetBridgeCounter()));
}

//bool mainwindow::ClickInBoard(const QPoint& click)
//{
//    if (click.x() > kHorizontalMarginSize && click.x() < m_boardSizePixels + kHorizontalMarginSize
//        && click.y() > kVerticalMarginSize && click.y() < m_boardSizePixels + kVerticalMarginSize)
//        return true;
//    return false;
//}
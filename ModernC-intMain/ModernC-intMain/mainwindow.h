#pragma once

#include <qpainter.h>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QTextEdit>
#include <QtWidgets/QMainWindow>
#include "ui_mainwindow.h"
#include "Game.h"

class mainwindow : public QMainWindow
{
	Q_OBJECT

public:
	const int kFoundationRadius = 6;
	const int kSquareSize = 20;
	const int kHorizontalMarginSize = 170;
	const int kVerticalMarginSize = 40;

public:
	mainwindow(QWidget* parent = nullptr, const int& boardSize = 24);
	~mainwindow();
	virtual void mouseReleaseEvent(QMouseEvent* e);
	virtual void paintEvent(QPaintEvent* e) override;
	//virtual void mouseMoveEvent(QMouseEvent* e);
	//virtual void mousePressEvent(QMouseEvent* e);

private:
	Game m_game;
	int m_boardSizeRects;
	int m_boardSizePixels;
	int m_windowWidth;
	int m_windowHeight;
	//bool ClickInBoard(const QPoint& click);
private:
	Ui::mainwindowClass ui;
};





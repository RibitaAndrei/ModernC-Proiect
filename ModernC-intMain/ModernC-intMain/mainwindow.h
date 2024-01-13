#include <qpainter.h>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QTextEdit>
#include <QLabel>
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
	const int kStartMenuItemsWidth = 200;
	const int kStartMenuItemsHeight = 80;
	const int kStartMenuItemsYOffset = 50;
	const int kInfoLabelsXOffset = 50;
	const int kInfoLabelsYOffset = 20;
	const int kInfoLabelsHeight = 50;
	const int kInfoLabelsWidth = 100;

public:
	mainwindow(QWidget* parent = nullptr, const int& boardSize = 24);
	~mainwindow();
	
private:
	virtual void mouseReleaseEvent(QMouseEvent* e);
	virtual void paintEvent(QPaintEvent* e) override;
	void DrawMainMenu(QPaintEvent* e);
	void DrawBoard(QPaintEvent* e);
	//virtual void mouseMoveEvent(QMouseEvent* e);
	//virtual void mousePressEvent(QMouseEvent* e);
private:
	Game m_game;
	int m_boardSizeRects;
	int m_boardSizePixels;
	int m_windowWidth;
	int m_windowHeight;
	bool m_gameStarted;
	bool m_userInfoPrompted;
	//bool ClickInBoard(const QPoint& click);
private:
	Ui::mainwindowClass ui;
private: //labels
	QLabel player1, player2;
	QLabel firstName, secondName;
	QLabel firstPilons, secondPilons;
	QLabel firstBridges, secondBridges;

	QRect titleText;
	QRect playButton;
	QRect quitButton;
	QRect setGameOptions;

	void SetLabelNames();
};





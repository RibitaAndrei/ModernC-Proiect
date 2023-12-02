//// twixtboardui.cpp
//
//#include "twixtboardui.h"
//
//TwixtBoardUI::TwixtBoardUI(QWidget* parent)
//	: QWidget(parent)
//{
//	boardSize = 24;  
//	gridLayout = new QGridLayout(this);
//	boardButtons = new QPushButton * *[boardSize];
//
//	for (int i = 0; i < boardSize; ++i)
//	{
//		boardButtons[i] = new QPushButton * [boardSize];
//
//		for (int j = 0; j < boardSize; ++j)
//		{
//			boardButtons[i][j] = new QPushButton(this);
//			gridLayout->addWidget(boardButtons[i][j], i, j);
//
//			connect(boardButtons[i][j], SIGNAL(clicked()), this, SLOT(onButtonClicked()));
//		}
//	}
//
//	setLayout(gridLayout);
//}
//
//TwixtBoardUI::~TwixtBoardUI()
//{
//	for (int i = 0; i < boardSize; ++i)
//	{
//		for (int j = 0; j < boardSize; ++j)
//		{
//			delete boardButtons[i][j];
//		}
//		delete[] boardButtons[i];
//	}
//	delete[] boardButtons;
//}
//
//void TwixtBoardUI::onButtonClicked()
//{
//	
//}

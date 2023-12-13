#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow w;
    w.show();
    return a.exec();
}


//#include<iostream>
//#include"Game.h"
//
//int main()
//{
//	Game game(24);
//	game.StartGame();
//
//	return 0;
//}
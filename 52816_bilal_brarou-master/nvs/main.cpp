#include "Game.h"
#include "GameView.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDir>
int main(int argc, char *argv[]) {

  QApplication a(argc, argv);

  MainWindow w;
  Board board(5, 5);
  Game model(board, 5);
  GameView *view = new GameView(model);
  w.setCentralWidget(view);
  w.show();
  return a.exec();
}

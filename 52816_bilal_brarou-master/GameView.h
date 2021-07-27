#ifndef GAMEVIEW_H
#define GAMEVIEW_H
#include "fileManager.h"
#include <CellView.h>
#include <Game.h>
#include <QComboBox>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QPushButton>
#include <iostream>
#include <vector>

/**
 * @brief The GameView class represent the view of the game
 */
class GameView : public QGraphicsView {
  Q_OBJECT

  QGraphicsTextItem *title;
  QGraphicsTextItem *winMsg;
  QGraphicsTextItem *lastNbMoves;
  QGraphicsTextItem *movesText;
  QGraphicsScene *gameScene;

  FileManager fm;

  Game &gm;
  size_t sizeRect = 500;

  QComboBox *bSize;
  QComboBox *nbColors;
  QPushButton *start;

  std::vector<std::vector<CellView *>> plateView;

public:
  /**
   * @brief GameView create the game view with a game model
   * @param game     the game model
   * @param parent   null
   */
  GameView(Game &game, QWidget *parent = 0);
  /**
   * @brief drawBoard draw the 2D plate
   */
  void drawBoard();
  /**
   * @brief drawButton draw the button for changing size of the play
   *                   start or change the number of colors
   */
  void drawButton();

  /**
   * @brief resizeTo resize the board of the game logicaly and graphicaly
   * @param x        the size of x to change the line length
   * @param y        the size of y to change the column length
   */
  void resizeTo(int x, int y);

  /**
   * @brief initialize initialize the windows of the game and all the text
   * needed
   */
  void initialize();

  /**
   * @brief initializeButton create button and them to the windows
   */
  void initializeButton();

  /**
   * @brief initialize_connection connect every cell of the game to a event
   */
  void initialize_connection();
  virtual ~GameView();
};

#endif // GAMEVIEW_H

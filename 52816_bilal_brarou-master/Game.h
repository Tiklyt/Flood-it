#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Color.h"

/**
 * @brief The Game class contains all the resources
 *        to play the game
 */
class Game {
private:
  Board &_bd;
  unsigned nbMove = 0;
  bool isFinished;
  unsigned nbColors;

public:
  /**
   * @brief Game  Create a Game with a board and a number of colors
   * @param board the board
   * @param nbColors the number of colors
   */
  Game(Board &board, unsigned nbColors);

  /**
   * @brief colorChanger Recursive functions that begin with x = 0 and y = 0
   *                     and will propage the board and change the colors
   *                     to the new Colors
   * @param x            x = 0
   * @param y            y = 0
   * @param oldColor     Color at plate[0][0]
   * @param newColor     The new colors that the user want to affect to the
   * other Cell
   */
  void colorChanger(unsigned short x, unsigned short y, Color oldColor,
                    Color newColor);

  /**
   * @brief incNbMove Increment the number of moves
   */
  void incNbMove();

  /**
   * @brief getNbColors get the number of colors
   */
  unsigned getNbColors() const;

  /**
   * @brief getNbMoves get the number of moves
   */
  unsigned getNbMoves() const;

  /**
   * @brief resetNbMove reset the number of moves
   */
  void resetNbMove();

  /**
   * @brief setNbColors  change the number of colors
   * @param colors      the new nb Colors
   */
  void setNbColors(unsigned colors);

  /**
   * @brief randomize change all the colors of the board randomly
   *
   */
  void randomize();

  /**
   * @brief hasWon Check if the user have won
   * @return true or false
   */
  bool hasWon();

  /**
   * @brief getBoard get the board class
   * @return a board reference
   */
  Board &getBoard();
};

#endif // GAME_H

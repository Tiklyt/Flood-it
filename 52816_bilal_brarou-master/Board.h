#ifndef BOARD_H
#define BOARD_H
#include "Cell.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

/**
 * @brief The Board class represent a plate 2D colors
 *        of the Flood-it Game.
 */
class Board {
  std::vector<std::vector<Cell *>> plate;
  size_t LIGNE;
  size_t COL;

public:
  /**
   * @brief Board Create a Board that contains
   *        Cells of Colors
   * @param x the x length of the plate
   * @param y the y length of the plate
   */
  Board(unsigned x, unsigned y);

  /**
   * @brief getPlate get the plate
   * @return a 2D vector of plate
   */
  std::vector<std::vector<Cell *>> &getPlate();

  /**
   * @brief resizeTo resize the plate to x LINE
   *                 and to y COLUMNS
   * @param x        the plate will have a LINE length of x
   * @param y        the plate will have a COL length of y
   */
  void resizeTo(int x, int y);

  /**
   * @brief getLigne get the line length
   * @return a unsigned int
   */
  size_t getLigne() const;

  /**
   * @brief getCol get the col length
   * @return a unsigned int
   */
  size_t getCol() const;

  /**
   * @brief ~Board delete all the dynamically allocated resources
   */
  virtual ~Board();
};

#endif // BOARD_H

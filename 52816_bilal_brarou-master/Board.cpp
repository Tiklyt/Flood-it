#include "Board.h"

Board::Board(unsigned x, unsigned y) : LIGNE(x), COL(y) {
  plate.resize(LIGNE);
  for (unsigned short i = 0; i < LIGNE; ++i)
    plate[i].resize(COL);
  for (unsigned i = 0; i < plate.size(); i++) {
    for (unsigned j = 0; j < plate[0].size(); j++) {
      plate[i][j] = new Cell;
    }
  }
}

void Board::resizeTo(int x, int y) {
  for (unsigned i = 0; i < LIGNE; i++) {
    for (unsigned j = 0; j < COL; j++) {
      delete plate[i][j];
    }
  }

  plate.resize(x);
  for (unsigned short i = 0; i < x; ++i)
    plate[i].resize(y);

  LIGNE = x;
  COL = y;

  for (unsigned i = 0; i < LIGNE; i++) {
    for (unsigned j = 0; j < COL; j++) {
      plate[i][j] = new Cell;
    }
  }
}

Board::~Board() {
  for (unsigned i = 0; i < LIGNE; i++) {
    for (unsigned j = 0; j < COL; j++) {
      delete plate[i][j];
    }
  }
}

std::vector<std::vector<Cell *>> &Board::getPlate() { return plate; }

size_t Board::getLigne() const { return LIGNE; }

size_t Board::getCol() const { return COL; }

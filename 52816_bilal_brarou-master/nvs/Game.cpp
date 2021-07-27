#include "Game.h"
Game::Game(Board &board, unsigned nbColors) : _bd(board), nbColors(nbColors) {}

void Game::colorChanger(unsigned short x, unsigned short y, Color oldColor,
                        Color newColor) {

  if (_bd.getPlate()[x][y]->getColor() != oldColor ||
      _bd.getPlate()[x][y]->getColor() == newColor) {
    return;
  }
  _bd.getPlate()[x][y]->setColor(newColor);

  if (x > 0) {
    colorChanger(x - 1, y, oldColor, newColor);
  }

  if (x < _bd.getLigne() - 1) {
    colorChanger(x + 1, y, oldColor, newColor);
  }

  if (y < _bd.getCol() - 1) {
    colorChanger(x, y + 1, oldColor, newColor);
  }

  if (y > 0) {
    colorChanger(x, y - 1, oldColor, newColor);
  }
}

void Game::resetNbMove() { nbMove = 0; }

unsigned Game::getNbMoves() const { return nbMove; }

void Game::incNbMove() { nbMove++; }

bool Game::hasWon() {
  for (unsigned i = 0; i < _bd.getLigne(); ++i) {
    for (unsigned j = 0; j < _bd.getCol(); ++j) {
      if (_bd.getPlate()[i][j]->getColor() !=
          _bd.getPlate()[0][0]->getColor()) {
        return false;
      }
    }
  }
  isFinished = true;
  return true;
}

unsigned Game::getNbColors() const { return nbColors; }

void Game::setNbColors(unsigned colors) {
  nbColors = colors;
  randomize();
}

void Game::randomize() {
  srand(time(0));
  for (size_t i = 0; i < _bd.getLigne(); i++) {
    for (size_t j = 0; j < _bd.getCol(); j++) {
      Color c = static_cast<Color>(rand() % nbColors);
      _bd.getPlate()[i][j]->setColor(c);
    }
  }
}

Board &Game::getBoard() { return _bd; }

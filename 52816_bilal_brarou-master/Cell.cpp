#include <Cell.h>
#include <iostream>
Cell::Cell(Color color) { this->color = color; }

void Cell::setColor(Color color) {
  this->color = color;
  notify();
}
const Color &Cell::getColor() { return this->color; }

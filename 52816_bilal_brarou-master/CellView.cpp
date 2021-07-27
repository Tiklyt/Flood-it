#include <CellView.h>
#include <Observable.h>
#include <QBrush>
#include <iostream>
CellView::CellView(Observable *obs, QGraphicsItem *parent)
    : QGraphicsRectItem(parent) {
  cell = (Cell *)obs;
  cell->attach(this);
}

Cell &CellView::getCell() { return *cell; }

void CellView::updateColor() {
  if (cell->getColor() == Color::BLUE) {
    setBrush(Qt::blue);
  } else if (cell->getColor() == Color::GREEN) {
    setBrush(Qt::green);
  } else if (cell->getColor() == Color::YELLOW) {
    setBrush(Qt::yellow);
  } else if (cell->getColor() == Color::PURPLE) {
    setBrush(QColor(186, 85, 211));
  } else if (cell->getColor() == Color::RED) {
    setBrush(Qt::red);
  } else if (cell->getColor() == Color::ORANGE) {
    setBrush(QColor(255, 165, 0));
  } else if (cell->getColor() == Color::PINK) {
    setBrush(QColor(236, 144, 205));
  } else if (cell->getColor() == Color::BROWN) {
    setBrush(QColor(153, 102, 51));
  } else if (cell->getColor() == Color::ROSE) {
    setBrush(QColor(204, 102, 51));
  } else if (cell->getColor() == Color::CYAN) {
    setBrush(QColor(51, 204, 204));
  }
}

void CellView::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (event)
    emit clicked();
}

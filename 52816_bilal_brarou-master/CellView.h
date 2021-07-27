#ifndef CELLVIEW_H
#define CELLVIEW_H
#include <Cell.h>
#include <Observable.h>
#include <Observer.h>
#include <QGraphicsRectItem>
#include <iostream>

/**
 * @brief The CellView class represent the graphical view of a cell class
 */
class CellView : public QObject, public Observer, public QGraphicsRectItem {
  Q_OBJECT
private:
  Cell *cell;

public:
  /**
   * @brief CellView  Create a cellView that represent a graphical colored
   * square that will be updated when ever he will notified to be changed
   * @param obs      The Cell that we to need to observe
   * @param parent   null
   */
  CellView(Observable *obs, QGraphicsItem *parent = 0);

  /**
   * @brief updateColor when the cellview is notified, the CellView
            will check the Cell Color to update his graphical color
            itself.
   */
  void updateColor();

  /**
   * @brief getCell get the cell
   * @return Cell Object
   */
  Cell &getCell();

  void update() override { updateColor(); }

  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
signals:
  void clicked();
};

#endif // CELLVIEW_H

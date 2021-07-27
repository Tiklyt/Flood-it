#ifndef CELL_H
#define CELL_H

#include <Color.h>
#include <Observable.h>
#include <Observer.h>
#include <vector>

/**
 * @brief The Cell class represent a Color Cell
 */
class Cell : public Observable {
private:
  Color color;
  std::vector<Observer *> observers;

public:
  /**
   * @brief Cell  Create a cell that contains one color
   * @param color color of the cell
   */
  Cell(Color color);

  virtual ~Cell() = default;
  Cell() = default;

  /**
   * @brief setColor change the color of the cell
   * @param color    color we need to make change
   */
  void setColor(Color color);

  /**
   * @brief getColor get the color from the cell
   * @return         a color enum
   */
  const Color &getColor();

  void notify() override {
    for (unsigned i = 0; i < observers.size(); i++) {
      observers[i]->update();
    }
  }

  void attach(Observer *observer) override { observers.push_back(observer); }
};

#endif // CELL_H

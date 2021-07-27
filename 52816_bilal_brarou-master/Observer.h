
#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief The Observable class represent the Observer component in the Observer
 *        DP see : https://en.wikipedia.org/wiki/Observer_pattern
 */
class Observer {

public:
  virtual void update() = 0;
};
#endif // OBSERVER_H

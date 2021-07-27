#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"

/**
 * @brief The Observable class represent the Subject component in the Observer
 * DP see : https://en.wikipedia.org/wiki/Observer_pattern
 */
class Observable {

public:
  virtual void attach(Observer *observer) = 0; // VP
  virtual void notify() = 0;                   // VP
};

#endif // SUBJECT_H

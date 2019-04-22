#ifndef TEST_H
#define TEST_H

#include "LinkedListOfInts.h"

class Test {
  public:
    Test();
    bool runTests();
  private:
    bool testIsEmpty();
    bool testSize();
    bool testAddandRemove();
    bool testSearch();
    void printList(LinkedListOfInts list);
};
#endif

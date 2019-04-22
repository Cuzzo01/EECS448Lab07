#include "Test.h"
#include "LinkedListOfInts.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::string;
using std::to_string;

Test::Test() {}

bool Test::runTests() {
  cout << "TEST: Beginning testIsEmpty.\n";
  cout << "TEST: Result of testIsEmpty is: " << testIsEmpty() << ".\n";
  cout << "TEST: Beginning testSize.\n";
  cout << "TEST: Result of testSize is: " << testSize() << ".\n";
  cout << "TEST: Beginning testAddandRemove.\n";
  cout << "TEST: Result of testAddandRemove is: " << testAddandRemove() << ".\n";
  cout << "TEST: Beginning testSearch.\n";
  cout << "TEST: Result of testSearch is: " << testSearch() << ".\n";
  return false;
}

bool Test::testIsEmpty() {
  LinkedListOfInts listToTest = LinkedListOfInts();
  bool toReturn = true;
  if (!listToTest.isEmpty()) {
    cout << "\tERROR: New list is not empty.\n";
    toReturn = false;
  }
  listToTest.addFront(1);
  if (listToTest.isEmpty()) {
    cout << "\tERROR: List with 1 element is empty.\n";
    toReturn = false;
  }
  listToTest.removeFront();
  if (!listToTest.isEmpty()) {
    cout << "\tERROR: List after element is removed is not empty.\n";
    toReturn = false;
  }
  return toReturn;
}

bool Test::testSize() {
  bool toReturn = true;
  LinkedListOfInts listToTest = LinkedListOfInts();
  if (listToTest.size() != 0) {
    cout << "\tERROR: Size of new list not 0\n";
  }
  for (int i = 0; i < 10; i++) {
    if (i%2 == 0) {
      listToTest.addFront(1);
    } else {
      listToTest.addBack(1);
    }
    if (unsigned(listToTest.size()) != listToTest.toVector().size()) {
      toReturn = false;
      cout << "\tERROR: Size of list does not match size of its vector.\n";
      cout << "\tSize of list is: " << listToTest.size() << ".\n";
      cout << "\tVector is: ";
      printList(listToTest);
    }
  }
  for (int i = 0; i < 10; i++) {
    if (i%2 == 0) {
      listToTest.removeFront();
    } else {
      listToTest.removeBack();
    }
    if (unsigned(listToTest.size()) != listToTest.toVector().size()) {
      toReturn = false;
      cout << "\tERROR: Size of list does not match size of its vector.\n";
      cout << "\tSize of list is: " << listToTest.size() << ".\n";
      cout << "\tVector is: ";
      printList(listToTest);
    }
  }
  return toReturn;
}

bool Test::testAddandRemove() {
  bool toReturn = true;
  LinkedListOfInts listToTest = LinkedListOfInts();
  std::vector<int> v;
  for (int i = 0; i < 10; i++) {
    if (i%2 == 0) {
      listToTest.addFront(i);
      if (listToTest.toVector().at(0) != i) {
        cout << "\tERROR: Added to front but value not found at front.\n";
        toReturn = false;
      }
    } else {
      listToTest.addBack(i);
      if (listToTest.toVector().at(listToTest.toVector().size()-1) != i) {
        cout << "\tERROR: Added to back but value not found at back.\n";
        toReturn = false;
      }
    }
  }
  // cout << "Starting remove tests, len of list is: " << listToTest.toVector().size() << ".\n";
  for (int i = 0; i < 5; i++) {
    if (i%2 == 0) {
      int valueOneBackFromFront = listToTest.toVector().at(1);
      unsigned int oldSize = listToTest.toVector().size();
      if (!listToTest.removeFront() && listToTest.toVector().size() != 0) {
        cout << "\tERROR: Tried to removeFront but method incorrectly returned false.\n";
        toReturn = false;
      }
      if (listToTest.toVector().at(0) != valueOneBackFromFront) {
        cout << "\tERROR: Removed from front but front value is not the value that was second.\n";
        toReturn = false;
      }
      if (listToTest.toVector().size() != oldSize-1) {
        cout << "\tERROR: Removed from front but size did not decrease by 1.\n";
        toReturn = false;
      }
    } else {
      int valueOneForwardFromBack = listToTest.toVector().at(listToTest.toVector().size()-2);
      unsigned int oldSize = listToTest.toVector().size();
      // printList(listToTest);
      if (!listToTest.removeBack() && listToTest.toVector().size() != 0) {
        cout << "\tERROR: Tried to removeBack but method incorrectly returned false.\n";
        toReturn = false;
      }
      // printList(listToTest);
      if (listToTest.toVector().at(listToTest.toVector().size()-1) != valueOneForwardFromBack) {
        cout << "\tERROR: Removed from back but back value is not value that was second from back.\n";
        toReturn = false;
      }
      if (listToTest.toVector().size() != oldSize-1) {
        cout << "\tERROR: Removed from back but size did not decrease by 1.\n";
        toReturn = false;
      }
    }
  }
  return toReturn;
}

bool Test::testSearch() {
  bool toReturn = true;
  LinkedListOfInts listToTest = LinkedListOfInts();
  if (listToTest.search(1) == true) {
    cout << "\tERROR: Element found in empty list.\n";
    toReturn = false;
  }
  for (int i = 0; i < 10; i++) {
    listToTest.addFront(i);
    if (listToTest.search(i) == false) {
      cout << "\tERROR: Element just added to list not found by search.\n";
      toReturn = false;
    }
    if (listToTest.search(i+1) == true) {
      cout << "\tERROR: Element not yet added to list was found in list.\n";
      toReturn = false;
    }
  }
  return toReturn;
}

void Test::printList(LinkedListOfInts list) {
  string output = "{";
  for (unsigned int i = 0; i < list.toVector().size(); i++) {
    if (i == 0) {
      output.append(to_string(list.toVector().at(i)));
    } else {
      output.append(", " + to_string(list.toVector().at(i)));
    }
  }
  output += "}\n";
  cout << output;
}

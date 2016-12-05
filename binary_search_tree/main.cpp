#include <iostream>
#include "BinarySearchTree.cpp"

using namespace std;

int main() {
  BinarySearchTree bst;
  bst.add(2);
  bst.add(1);
  bst.add(3);
  bst.remove(2);
  bst.add(2);
  bst.add(15);
  bst.add(10);
  bst.add(20);
  bst.add(25);
  bst.add(8);
  bst.add(12);
  bst.remove(12);

  bst.print_tree();
  int number;
  cout << "Enter number to be searched: " << endl;
  cin >> number;
  if (bst.search(number) == true) {
    cout << "Number found" << endl;
  } else {
    cout << "Number not found" << endl;
  }
}

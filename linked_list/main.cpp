#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int main() {
  LinkedList list;
  list.add(2);
  list.add(1);
  list.add(3);
  list.insert(100, 0);
  list.add(2);
  list.add(15);
  list.add(10);
  list.add(20);
  list.add(25);
  list.add(8);
  list.add(12);

  list.print_list();
  int number;
  cout << "Enter number to be searched: " << endl;
  cin >> number;
  if (list.exists(number)) {
    cout << "Number found" << endl;
  } else {
    cout << "Number not found" << endl;
  }
}

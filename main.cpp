#include <iostream>
#include <cstdlib>
#include <string>
#include "BST.cpp"

using namespace std;

int main() {
  int treeKeys[15] = {50, 76, 21, 4, 32, 64, 15, 14, 100, 83,2, 3, 70, 87, 80};
  BST myTree; 

  // Before adding numebrs

  cout << "Printing the tree in order before adding numbers\n";
  myTree.PrintInOrder();

  // Adding numebrs

  for (int i=0; i<15; i++) {
    myTree.AddLeaf(treeKeys[i]);
  }

  // After adding numbers

  cout << "Printing the tree in order before adding numbers\n";
  myTree.PrintInOrder();

  // Printing the children

  myTree.PrintChildren(50);

  // Printing the smallest key

  try {
    cout << "Samllest key: " << myTree.SmallestKey() << "\n"; 
  } catch(string err) {
    cout << err << "\n";
  }
}

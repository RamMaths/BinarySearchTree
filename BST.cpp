#include <iostream>
#include <cstdlib>
#include <string>
#include "BST.h"

using namespace std;

// Private Section

void BST::AddLeafPrivate(int key, node* ptr) {
  if(root == NULL) {
    root = CreateLeaf(key);
  } else if (key < ptr->key) {
    if(ptr->left != NULL) {
      AddLeafPrivate(key, ptr->left);
    } else {
      ptr->left = CreateLeaf(key);
    }
  } else if (key > ptr->key) {
    if(ptr -> right != NULL) {
      AddLeafPrivate(key, ptr->right);
    } else {
      ptr->right = CreateLeaf(key);
    }
  } else {
    cout << "The key " << key << " has already been added to the tree" << "\n";
  }
}

void BST::PrintInOrderPrivate(node* ptr) {
  if(ptr == NULL) return;

  PrintInOrderPrivate(ptr->left);
  cout << "key: " << ptr->key << "\n";
  PrintInOrderPrivate(ptr->right);
}

void BST::PrintPreOrderPrivate(node* ptr) {
  if(ptr == NULL) return;

  cout << "key: " << ptr->key << "\n";
  PrintInOrderPrivate(ptr->left);
  PrintInOrderPrivate(ptr->right);
}

void BST::PrintPostOrderPrivate(node* ptr) {
  if(ptr == NULL) return;

  PrintInOrderPrivate(ptr->left);
  PrintInOrderPrivate(ptr->right);
  cout << "key: " << ptr->key << "\n";
}

BST::node* BST::ReturnNodePrivate(int key, node* ptr) {
  if (ptr == NULL) return NULL;
  if (ptr->key == key) return ptr;
  else if(key < ptr->key)  {
    return ReturnNodePrivate(key, ptr->left);
  } else {
    return ReturnNodePrivate(key, ptr->right);
  }
}

int BST::SmallestKeyPrivate(node* ptr) {
  if(ptr->left == NULL) {
    return ptr->key;
  } else {
    return SmallestKeyPrivate(ptr->left);
  }
}

int BST::CalculateHeightPrivate(node* ptr) {
  if(ptr == NULL) return -1;

  int leftHeight = CalculateHeightPrivate(ptr->left);
  int rightHeight = CalculateHeightPrivate(ptr->right);
  return std::max(leftHeight, rightHeight) + 1;
}

// Public Section

BST::BST() {
  root = NULL;
}

BST::node* BST::CreateLeaf(int key) {
  node* n = new node;
  n->key = key;
  n->left = NULL;
  n->right = NULL;

  return n;
}

void BST::AddLeaf(int key) {
  BST::AddLeafPrivate(key, root);
}

void BST::PrintInOrder() {
  if (root == NULL) {
    cout << "The tree is empty" << "\n";
  } else {
    BST::PrintInOrderPrivate(root);
  }
}

void BST::PrintPreOrder() {
  if (root == NULL) {
    cout << "The tree is empty" << "\n";
  } else {
    BST::PrintInOrderPrivate(root);
  }
}

void BST::PrintPostOrder() {
  if (root == NULL) {
    cout << "The tree is empty" << "\n";
  } else {
    BST::PrintInOrderPrivate(root);
  }
}

BST::node* BST::ReturnNode(int key) {
    return ReturnNodePrivate(key, root);
}

void BST::PrintChildren(int key) {
  if (root == NULL) {
    cout << "The tree is empty" << "\n";
  } else {
    node* n = BST::ReturnNode(key);

    cout << "Parent Node: " << n->key << "\n";

    n->left == NULL ?
      cout << "Left: NULL" :
      cout << "Left: " << n->left->key << "\n";

    n->right == NULL ?
      cout << "Right: NULL" :
      cout << "Right: " << n->right->key << "\n";
  }
}

int BST::SmallestKey() {
  if (root != NULL) {
    return BST::SmallestKeyPrivate(root);
  } else {
    string s = "The tree is empty";
    throw s;
  }
}

int BST::CalculateHeight() {
  if(root == NULL) {
    string s = "The tree is empty";
    throw s;
  } else {
    return BST::CalculateHeightPrivate(root);
  }
}

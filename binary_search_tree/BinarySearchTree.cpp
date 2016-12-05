#include <iostream>

using namespace std;

class BinarySearchTree {
public:
  struct Node {
    int data;
    Node* left;
    Node* right;
  };

  BinarySearchTree() {
    this->root = NULL;
  }

  bool search(int data) {
    Node* node = tree_search(this->root, data);
    if (node == NULL) return false;
    return true;
  }

  void add(int data) {
    if (tree_search(this->root, data) != NULL) {
      cout << "Error: Cannot add " << data << " as it already exists." << endl;
    } else {
      this->root = insert_node(this->root, data);
    }
  }

  void remove(int data) {
    this->root = delete_node(this->root, data);
  }

  void print_tree() {
    print_node(this->root);
  }

private:
  Node* root;

  Node* tree_search(Node* node, int data) {
    if (node == NULL)            return NULL;
    else if (node->data == data) return node;
    else if (data <= node->data) return tree_search(node->left, data);
    else return tree_search(node->right, data);
  }

  Node* new_node(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
  }

  Node* insert_node(Node* node, int data) {
    if (node == NULL) node = new_node(data);
    else if (data <= node->data) node->left = insert_node(node->left, data);
    else node->right = insert_node(node->right, data);
    return node;
  }

  Node* print_node(Node* node) {
    if (node == NULL) {
      return NULL;
    }
    else {
      cout << "NODE: " << node << ", DATA: " << node->data << ", ";
      cout << "LEFT: " << node->left << ", ";
      if (node->left != NULL) {
        cout << node->left->data;
      } else cout << "NULL";
      cout << ", ";
      cout << "RIGHT: " << node->right << ", ";
      if (node->right != NULL) {
        cout << node->right->data;
      } else cout << "NULL";
      cout << endl;
      print_node(node->left);
      print_node(node->right);
    }
    return node;
  }

  Node* delete_node(Node* node, int data) {
    if (node == NULL) {
      return NULL;
    }
    else if (data < node->data) {
      node->left = delete_node(node->left, data);
    }
    else if (data > node->data) {
      node->right = delete_node(node->right, data);
    }
    else if (data == node->data) {
      if (node->left == NULL && node->right == NULL) {
        delete node;
        node = NULL;
      }
      else if (node->left == NULL) {
        Node *temp = root;
        node = node->right;
        delete temp;
      }
      else if (root->right == NULL) {
        Node *temp = root;
        node = node->left;
        delete temp;
      }
      else {
        Node *temp = min(root->right);
        node->data = temp->data;
        node->right = delete_node(node->right, temp->data);
      }
    }
    return node;
  }

  Node* min(Node* node) {
    if (node == NULL) {
      return NULL;
    }
    if (node->left != NULL) {
      return min(node->left);
    }
    return node;
  }
};

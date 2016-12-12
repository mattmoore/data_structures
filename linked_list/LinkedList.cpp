#include <iostream>
#include <sstream>

using namespace std;

class LinkedList {
public:
  struct Node {
    int data;
    Node* next;
  };

  LinkedList() {
    this->node_length = 0;
    this->head = NULL;
    this->tail = NULL;
  }

  bool exists(int data) {
    Node* node = search(this->head, data);
    if (node) {
      return true;
    }
    return false;
  }

  void insert(int data, int position) {
    insert_node(this->head, data, position, 0);
  }

  void add(int data) {
    Node* node = new_node(data);
    if (this->head == NULL) {
      this->head = node;
      this->tail = node;
    } else {
      this->tail->next = node;
      this->tail = node;
    }
    this->node_length++;
  }

  void remove(int position) {
    remove_node(this->head, position, 0);
  }

  void print_list() {
    stringstream stream;
    stream << "HEAD: " << this->head << ", " << this->head->data << endl;
    print_node(this->head, stream);
    stream << "TAIL: " << this->tail << ", " << this->tail->data << endl;
    cout << stream.str();
  }

private:
  Node* head;
  Node* tail;
  int node_length;

  Node* new_node(int data) {
    Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
  }

  Node* insert_node(Node* node, int data, int position, int index) {
    if (node == NULL) {
      return NULL;
    }
    if (index != position) {
      return insert_node(node->next, data, position, index + 1);
    } else {
      Node* next = new_node(node->data);
      next->next = node->next;
      node->data = data;
      node->next = next;
      this->node_length++;
    }
    return node;
  }

  Node* remove_node(Node* node, int position, int index) {
    if (node == NULL) {
      return NULL;
    }
    if (position != index) {
      return remove_node(node->next, position, index + 1);
    }
    if (node->next) {
      Node* next = node->next;
      node->data = next->data;
      node->next = next->next;
      delete next;
      next = NULL;
    } else {
      delete node;
      node = NULL;
    }
    this->tail = find_tail(this->head);
    return node;
  }

  Node* print_node(Node* node, stringstream& stream) {
    if (node == NULL) {
      return NULL;
    }
    stream << node << ", " << node->data << ", NEXT: " << node->next << endl;
    if (node->next) {
      print_node(node->next, stream);
    }
    return node;
  }

  Node* search(Node* node, int data) {
    if (node == NULL) {
      return NULL;
    }
    if (node->data != data) {
      return search(node->next, data);
    }
    return node;
  }

  Node* find_parent(Node* node) {
    if (node == NULL) {
      return NULL;
    }
    if (node->next != node) {
      return find_parent(node->next);
    }
    return node;
  }

  Node* find_tail(Node* node) {
    if (node == NULL) {
      return NULL;
    }
    if (node->next) {
      return find_tail(node->next);
    }
    return node;
  }
};

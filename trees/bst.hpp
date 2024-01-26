#ifndef BST_HEADER
#define BST_HEADER

#include "node.hpp"
#include <cctype>
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <vector>

template <typename T, typename U> class BST {
  Node<T, U> *root;
  std::function<bool(T, T)> m_comparator;
  size_t m_size;
  size_t m_height;

public:
  BST();
  BST(std::function<bool(T)> comparator);

  void add(T key);
  void add(T key, U value);
  void remove(T key);
  void add_helper(Node<T, U> *curr, Node<T, U> *node);
  std::optional<U> get(T key) const;
  bool contains(T key) const;
  std::vector<std::pair<T, std::optional<U>>> preorder() const;
  std::vector<std::pair<T, std::optional<U>>> inorder() const;
  std::vector<std::pair<T, std::optional<U>>> postorder() const;
  bool empty() const;
  int size() const;
  int height() const;
  void print(std::string order = "inorder") const;
  void print_helper(Node<T, U> *node, std::string order) const;
};

template <typename T, typename U>
BST<T, U>::BST()
    : root(nullptr), m_comparator([](T a, T b) -> bool { return a > b; }),
      m_size(0), m_height(0) {}

template <typename T, typename U>
BST<T, U>::BST(std::function<bool(T)> comparator)
    : root(nullptr), m_comparator(comparator), m_size(0), m_height(0){};

template <typename T, typename U> void BST<T, U>::add(T key) {
  Node<T, U> *node = new Node<T, U>(key);
  if (empty()) {
    root = node;
  } else {
    add_helper(root, node);
  }
  m_size++;
}

template <typename T, typename U>
void BST<T, U>::add_helper(Node<T, U> *curr, Node<T, U> *node) {
  bool goleft = m_comparator(curr->key(), node->key());
  if (goleft && curr->hasleft()) {
    add_helper(curr->left(), node);
  } else if (goleft) {
    curr->addleft(node);
  } else if (curr->hasright()) {
    add_helper(curr->right(), node);
  } else {
    curr->addright(node);
  }
}

template <typename T, typename U> bool BST<T, U>::empty() const {
  return m_size == 0;
}

template <typename T, typename U>
void BST<T, U>::print(std::string order) const {
  print_helper(root, order);
  std::cout << "\n";
}

template <typename T, typename U>
void BST<T, U>::print_helper(Node<T, U> *node, std::string order) const {
  if (node == nullptr) {
    return;
  }
  if (order == "preorder") {
    std::cout << node->key() << ": "
              << (node->value().has_value()
                      ? std::to_string(node->value().value())
                      : "null");
    std::cout << " ";
  }
  print_helper(node->left(), order);
  if (order == "inorder") {
    std::cout << node->key() << ": "
              << (node->value().has_value()
                      ? std::to_string(node->value().value())
                      : "null");
    std::cout << " ";
  }
  print_helper(node->right(), order);
  if (order == "postorder") {
    std::cout << node->key() << ": "
              << (node->value().has_value()
                      ? std::to_string(node->value().value())
                      : "null");
    std::cout << " ";
  }
}

#endif

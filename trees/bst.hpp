#ifndef BST_HEADER
#define BST_HEADER

#include "node.hpp"
#include <functional>
#include <optional>

template <typename T, typename U> class BST {
  Node<T> *root;
  std::function<bool(T)> m_comparator;
  size_t m_size;
  size_t m_height;

public:
  BST();
  BST(std::function<bool(T)> comparator);

  void add(T key);
void remove(T key);
  T get(T key);
  int size() const;
  int height() const;
  int print(std::string order = "ino");
};

#include "bst.tpp"

#endif

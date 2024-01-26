#ifndef BST_HEADER
#define BST_HEADER

#include "node.hpp"
#include <functional>
#include <optional>
#include <utility>
#include <vector>

template <typename T, typename U> class BST {
  Node<T, U> *root;
  std::function<bool(T)> m_comparator;
  size_t m_size;
  size_t m_height;

public:
  BST();
  BST(std::function<bool(T)> comparator);

  void add(T key);
  void add(T key, U value);
  void remove(T key);
  std::optional<U> get(T key) const;
  bool contains(T key) const;
  std::vector<std::pair<T, std::optional<U>>> preorder() const;
  std::vector<std::pair<T, std::optional<U>>> inorder() const;
  std::vector<std::pair<T, std::optional<U>>> postorder() const;
  int size() const;
  int height() const;
  int print(std::string order = "ino");
};

#include "bst.tpp"

#endif

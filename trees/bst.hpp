#ifndef BST_HEADER
#define BST_HEADER

#include "node.hpp"
#include <functional>
#include <optional>
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
  std::optional<U> get(T key) const;
  bool contains(T key) const;
  std::vector<std::pair<T, std::optional<U>>> preorder() const;
  std::vector<std::pair<T, std::optional<U>>> inorder() const;
  std::vector<std::pair<T, std::optional<U>>> postorder() const;
  bool empty() const;
  int size() const;
  int height() const;
  int print(std::string order = "ino");
};

template <typename T, typename U>
BST<T, U>::BST()
    : root(nullptr), m_comparator([](T a, T b) -> bool { return a > b; }),
      m_size(0), m_height(0) {}

template <typename T, typename U>
BST<T, U>::BST(std::function<bool(T)> comparator)
    : root(nullptr), m_comparator(comparator), m_size(0), m_height(0){};

template <typename T, typename U> void BST<T, U>::add(T key) {
    if (empty()) {
        root = new Node<T, U>(key);
    } else {
    }
    m_size++;
}

template <typename T, typename U> bool BST<T, U>::empty() const {
  return m_size == 0;
}

#endif

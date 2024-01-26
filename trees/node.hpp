#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <optional>

template <typename T, typename U> class Node {
  T m_key;
  std::optional<U> m_value;
  Node<T, U> *m_left;
  Node<T, U> *m_right;

public:
  Node(T key)
      : m_key(key), m_value(std::nullopt), m_left(nullptr), m_right(nullptr) {}
  Node(T key, U value)
      : m_key(key), m_value(std::optional<U>(value)), m_left(nullptr),
        m_right(nullptr) {}

  T key() const { return m_key; }
  std::optional<U> value() const { return m_value; }
  Node<T, U> *left() const { return m_left; }
  Node<T, U> *right() const { return m_right; }
  void addleft(Node<T, U> *node) { m_left = node; }
  void addright(Node<T, U> *node) { m_right = node; }
  void print() const {
    std::cout << m_key << ": ";
    if (m_value.has_value()) {
      std::cout << m_value.value();
    } else {
      std::cout << "null";
    }
    std::cout << "\n";
  }
};

#endif

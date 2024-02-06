#ifndef BST_HEADER
#define BST_HEADER

#include "node.hpp"
#include <exception>
#include <functional>
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

  void add(const T key);
  void add(const T key, const U value);
  void add_helper(Node<T, U> *curr, Node<T, U> *node);
  std::optional<U> get(const T key) const;
  std::optional<U> get_helper(const Node<T, U> *node, const T key) const;
  bool contains(const T key) const;
  bool contains_helper(const Node<T, U> *node, const T key) const;
  void remove(const T key);
  Node<T, U> *remove_helper(Node<T, U> *node, const T key);
  Node<T, U> *get_min_node(Node<T, U> *node);
  std::vector<std::pair<T, std::optional<U>>> preorder() const;
  std::vector<std::pair<T, std::optional<U>>>
  preorder_helper(Node<T, U> *node,
                  std::vector<std::pair<T, std::optional<U>>> &vec) const;
  std::vector<std::pair<T, std::optional<U>>> inorder() const;
  std::vector<std::pair<T, std::optional<U>>>
  inorder_helper(Node<T, U> *node,
                 std::vector<std::pair<T, std::optional<U>>> &vec) const;
  std::vector<std::pair<T, std::optional<U>>> postorder() const;
  std::vector<std::pair<T, std::optional<U>>>
  postorder_helper(Node<T, U> *node,
                   std::vector<std::pair<T, std::optional<U>>> &vec) const;
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

template <typename T, typename U> void BST<T, U>::add(const T key) {
  Node<T, U> *node = new Node<T, U>(key);
  if (empty()) {
    root = node;
  } else {
    add_helper(root, node);
  }
  m_size++;
}

template <typename T, typename U>
void BST<T, U>::add(const T key, const U value) {
  Node<T, U> *node = new Node<T, U>(key, value);
  if (empty()) {
    root = node;
  } else {
    add_helper(root, node);
  }
  m_size++;
}

template <typename T, typename U>
void BST<T, U>::add_helper(Node<T, U> *curr, Node<T, U> *node) {
  bool go_left = m_comparator(curr->key(), node->key());
  if (go_left && curr->hasleft()) {
    add_helper(curr->left(), node);
  } else if (go_left) {
    curr->addleft(node);
  } else if (curr->hasright()) {
    add_helper(curr->right(), node);
  } else {
    curr->addright(node);
  }
}

template <typename T, typename U>
std::optional<U> BST<T, U>::get(const T key) const {
  if (contains(key) == false) {
    throw std::exception();
  }
  return get_helper(root, key);
}

template <typename T, typename U>
std::optional<U> BST<T, U>::get_helper(const Node<T, U> *node, const T key) const {
  if (node->key() == key) {
    return node->value();
  }
  if (node->hasleft() && m_comparator(node->key(), key)) {
    return get_helper(node->left(), key);
  }
  return get_helper(node->right(), key);
}

template <typename T, typename U> bool BST<T, U>::contains(const T key) const {
  if (empty()) {
    return false;
  }
  return contains_helper(root, key);
}

template <typename T, typename U>
bool BST<T, U>::contains_helper(const Node<T, U> *node, const T key) const {
  if (node == nullptr) {
    return false;
  }
  if (node->key() == key) {
    return true;
  }
  bool go_left = m_comparator(node->key(), key);
  if (go_left) {
    return contains_helper(node->left(), key);
  }
  return contains_helper(node->right(), key);
}

template <typename T, typename U> void BST<T, U>::remove(const T key) {
  if (contains(key) == false) {
    throw std::exception();
  }
  if (size() == 1) {
    delete root;
    root = nullptr;
  } else {
    Node<T, U> *_ = remove_helper(root, key);
  }
  m_size--;
}

template <typename T, typename U>
Node<T, U> *BST<T, U>::remove_helper(Node<T, U> *node, const T key) {
  if (node == nullptr) {
    return nullptr;
  }

  if ((node->key() != key) && m_comparator(node->key(), key)) {
    node->addleft(remove_helper(node->left(), key));
  } else if ((node->key() != key)) {
    node->addright(remove_helper(node->right(), key));
  } else {
    if (node->hasleft() == false) {
      Node<T, U> *tmp = node->right();
      delete node;
      return tmp;
    } else if (node->hasright() == false) {
      Node<T, U> *tmp = node->left();
      delete node;
      return tmp;
    } else {
      Node<T, U> *min_node = get_min_node(node->right());
      node->set(min_node->key(), min_node->value());
      node->addright(remove_helper(node->right(), min_node->key()));
    }
  }
  return node;
}

template <typename T, typename U>
Node<T, U> *BST<T, U>::get_min_node(Node<T, U> *node) {
  while (node && node->hasleft()) {
    node = node->left();
  }
  return node;
}

template <typename T, typename U>
std::vector<std::pair<T, std::optional<U>>> BST<T, U>::preorder() const {
  std::vector<std::pair<T, std::optional<U>>> vec;
  return preorder_helper(root, vec);
}

template <typename T, typename U>
std::vector<std::pair<T, std::optional<U>>> BST<T, U>::preorder_helper(
    Node<T, U> *node, std::vector<std::pair<T, std::optional<U>>> &vec) const {
  if (node == nullptr) {
    return vec;
  }
  vec.push_back(std::pair<T, std::optional<U>>(
      node->key(), std::optional<U>(node->value())));
  preorder_helper(node->left(), vec);
  preorder_helper(node->right(), vec);
  return vec;
}

template <typename T, typename U>
std::vector<std::pair<T, std::optional<U>>> BST<T, U>::inorder() const {
  std::vector<std::pair<T, std::optional<U>>> vec;
  return inorder_helper(root, vec);
}

template <typename T, typename U>
std::vector<std::pair<T, std::optional<U>>> BST<T, U>::inorder_helper(
    Node<T, U> *node, std::vector<std::pair<T, std::optional<U>>> &vec) const {
  if (node == nullptr) {
    return vec;
  }
  inorder_helper(node->left(), vec);
  vec.push_back(std::pair<T, std::optional<U>>(
      node->key(), std::optional<U>(node->value())));
  inorder_helper(node->right(), vec);
  return vec;
}

template <typename T, typename U>
std::vector<std::pair<T, std::optional<U>>> BST<T, U>::postorder() const {
  std::vector<std::pair<T, std::optional<U>>> vec;
  return postorder_helper(root, vec);
}

template <typename T, typename U>
std::vector<std::pair<T, std::optional<U>>> BST<T, U>::postorder_helper(
    Node<T, U> *node, std::vector<std::pair<T, std::optional<U>>> &vec) const {
  if (node == nullptr) {
    return vec;
  }
  postorder_helper(node->left(), vec);
  postorder_helper(node->right(), vec);
  vec.push_back(std::pair<T, std::optional<U>>(
      node->key(), std::optional<U>(node->value())));
  return vec;
}

template <typename T, typename U> int BST<T, U>::size() const { return m_size; }

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

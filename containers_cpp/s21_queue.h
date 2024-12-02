#ifndef S21_queue_H
#define S21_queue_H

#include <initializer_list>
#include <iostream>

namespace s21 {
template <typename T>
class queue {
 public:
  // Type aliases
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = std::size_t;

  // Constructors
  queue();
  explicit queue(std::initializer_list<value_type> const& items);
  queue(const queue& q);
  queue(queue&& q) noexcept;
  ~queue();
  queue& operator=(queue&& q) noexcept;

  // Element access
  const_reference front() const;
  const_reference back() const;

  // Capacity
  bool empty() const;
  size_type size() const;

  // Modifiers
  void push(const_reference value);
  void pop();
  void swap(queue& other) noexcept;

  template <typename... Args>
  void insert_many_back(Args&&... args);

 private:
  struct Node {
    T data;
    Node* next;
    explicit Node(const T& data) : data(data), next(nullptr) {}
  };

  Node* frontNode;
  Node* rearNode;
  size_type count;

  void clear();
};

// Implementation

// Constructors
template <typename T>
queue<T>::queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

template <typename T>
queue<T>::queue(std::initializer_list<value_type> const& items)
    : frontNode(nullptr), rearNode(nullptr), count(0) {
  for (const auto& item : items) {
    push(item);
  }
}

template <typename T>
queue<T>::queue(const queue& q)
    : frontNode(nullptr), rearNode(nullptr), count(0) {
  Node* current = q.frontNode;
  while (current) {
    push(current->data);
    current = current->next;
  }
}

template <typename T>
queue<T>::queue(queue&& q) noexcept
    : frontNode(q.frontNode), rearNode(q.rearNode), count(q.count) {
  q.frontNode = nullptr;
  q.rearNode = nullptr;
  q.count = 0;
}

template <typename T>
queue<T>::~queue() {
  clear();
}

template <typename T>
queue<T>& queue<T>::operator=(queue&& q) noexcept {
  if (this != &q) {
    clear();
    frontNode = q.frontNode;
    rearNode = q.rearNode;
    count = q.count;
    q.frontNode = nullptr;
    q.rearNode = nullptr;
    q.count = 0;
  }
  return *this;
}

// Element access
template <typename T>
typename queue<T>::const_reference queue<T>::front() const {
  if (empty()) {
    throw("queue is empty");
  }
  return frontNode->data;
}

template <typename T>
typename queue<T>::const_reference queue<T>::back() const {
  if (empty()) {
    throw("queue is empty");
  }
  return rearNode->data;
}

// Capacity
template <typename T>
bool queue<T>::empty() const {
  return count == 0;
}

template <typename T>
typename queue<T>::size_type queue<T>::size() const {
  return count;
}

// Modifiers
template <typename T>
void queue<T>::push(const_reference value) {
  Node* newNode = new Node(value);
  if (empty()) {
    frontNode = rearNode = newNode;
  } else {
    rearNode->next = newNode;
    rearNode = newNode;
  }
  ++count;
}

template <typename T>
void queue<T>::pop() {
  if (empty()) {
    throw("queue is empty");
  }
  Node* temp = frontNode;
  frontNode = frontNode->next;
  delete temp;
  --count;
  if (empty()) {
    rearNode = nullptr;
  }
}

template <typename T>
void queue<T>::swap(queue& other) noexcept {
  std::swap(frontNode, other.frontNode);
  std::swap(rearNode, other.rearNode);
  std::swap(count, other.count);
}

template <typename T>
void queue<T>::clear() {
  while (!empty()) {
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    --count;
    if (empty()) {
      rearNode = nullptr;
    }
  }
}

template <typename T>
template <typename... Args>
void queue<T>::insert_many_back(Args&&... args) {
  (push(std::forward<Args>(args)), ...);
}
}  // namespace s21
#endif  // S21_queue_H

#ifndef __STACK_H__
#define __STACK_H__
#include <initializer_list>
namespace s21 {
template <typename T>
class stack {
  // Stack Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

 public:
  // Stack Member functions
  stack() : topic_(nullptr), size_(0){};
  explicit stack(std::initializer_list<value_type> const& items) : stack() {
    for (const auto& it : items) {
      this->push(it);
    }
  }
  stack(const stack& other) : stack() { *this = other; }
  stack(stack&& other) : stack() { this->swap(other); }
  ~stack() {
    size_type tmp = size_;
    for (size_type i = 0; i < tmp; i++) {
      pop();
    }
  }

  // operators
  stack& operator=(stack&& other) {
    this->swap(other);
    return *this;
  }
  stack& operator=(const stack& other) {
    if (this != &other) {
      while (topic_) {
        pop();
      }
      std::vector<value_type> buffer_stack;
      Node* buff_node = other.topic_;
      for (size_type i = 0; i < other.size_; i++) {
        buffer_stack.push_back(buff_node->data_);
        buff_node = buff_node->prev_;
      }
      for (int i = other.size_ - 1; i > -1; i--) {
        push(buffer_stack[i]);
      }
    }
    return *this;
  }

  // Stack Element access
  const_reference top() const { return topic_->data_; }

  // Stack Capacity
  bool empty() { return !topic_; }
  size_type size() { return size_; }

  // Stack Modifiers
  void push(const_reference value) {
    Node* tmp = new Node;
    tmp->prev_ = topic_;
    tmp->data_ = value;
    topic_ = tmp;
    size_++;
  }
  void pop() {
    if (topic_ != nullptr) {
      Node* tmp = topic_;
      topic_ = topic_->prev_;
      delete tmp;
      size_--;
    }
  }
  void swap(stack& other) {
    size_type buff_size = size_;
    Node* buff_node = topic_;
    size_ = other.size_;
    topic_ = other.topic_;
    other.size_ = buff_size;
    other.topic_ = buff_node;
  }

  // Bonus functions
  template <class... Args>
  void insert_many_front(Args... args) {
    push(T(args...));
  }

  struct Node {
    value_type data_;
    Node* prev_;
  };

 private:
  Node* topic_;
  size_type size_;
};

}  // namespace s21
#endif

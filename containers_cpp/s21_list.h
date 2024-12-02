#ifndef S21_LIST_H
#define S21_LIST_H

#include <cmath>
#include <iostream>

namespace s21 {
template <typename T>
class list {
 public:
  // List Member Type
  class ListIterator;
  class ConstListIterator;
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  using iterator = ListIterator;
  using const_iterator = const ListIterator;

 private:
  // uzel
  struct Node {
    value_type data;
    Node* next;
    Node* prev;
    Node(const_reference value) : data(value), next(nullptr), prev(nullptr) {}
  };

  Node* head;
  Node* tail;
  size_type list_size;

 public:
  class ListIterator {
   public:
    Node* n_current;

    // Constructors & destructor
    ListIterator() : n_current(nullptr) {}
    explicit ListIterator(Node* node) : n_current(node) {}

    // overload operators
    reference operator*() { return n_current->data; }
    Node* operator->() { return n_current; }

    ListIterator& operator++() {
      n_current = n_current->next;
      return *this;
    }
    ListIterator operator++(int) {
      ListIterator tmp = *this;
      ++(*this);
      return tmp;
    }

    ListIterator& operator--() {
      n_current = n_current->prev;
      return *this;
    }
    ListIterator operator--(int) {
      ListIterator tmp = *this;
      --(*this);
      return tmp;
    }

    bool operator==(const ListIterator& other) const {
      return n_current == other.n_current;
    }
    bool operator!=(const ListIterator& other) const {
      return n_current != other.n_current;
    }
  };

  class ConstListIterator : public ListIterator {
   public:
    ConstListIterator() : ListIterator() {}
    explicit ConstListIterator(Node* node) : ListIterator(node) {}
    const_reference operator*() const { return this->n_current->data; }
  };

  // iterator
  iterator begin() { return iterator(head); }
  iterator end() { return iterator(tail); }
  const_iterator begin() const { return const_iterator(head); }
  const_iterator end() const { return const_iterator(tail); }

  // List Functions
  list();             // empty list
  list(size_type n);  // parameterized size(n) constructor
  list(std::initializer_list<value_type> const&
           items);  // list initizialized using std::initializer_list {a, b, c,
                    // ...}
  list(const list& l);  // copy
  list(list&& l);       // move
  ~list();

  // Operators
  list& operator=(list&& l);
  list& operator=(const list& l);

  // List Element access
  const_reference front();
  const_reference back();

  // Capacity
  bool empty();
  size_type size();
  size_type max_size();

  // Modifiers
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(list& other);
  void merge(list& other);
  void splice(const_iterator pos, list& other);
  void reverse();  // reverses the order of the elements
  void unique();   // removes consecutive duplicate elements
  void sort();

  // Additional modifiers
  Node* merge(Node* left, Node* right);

  // // Bonus functions
  template <class... Args>
  iterator emplace(const_iterator pos, Args&&... args);

  template <class... Args>
  void emplace_back(Args&&... args);

  template <class... Args>
  void emplace_front(Args&&... args);
};
}  // namespace s21

namespace s21 {

template <typename T>
list<T>::list() : head(nullptr), tail(nullptr), list_size(0) {}

template <typename T>
list<T>::list(size_type n) : head(nullptr), tail(nullptr), list_size(0) {
  for (size_type i = 0; i < n; i++) {
    push_back(value_type());
  }
}

template <typename T>
list<T>::list(std::initializer_list<value_type> const& items)
    : head(nullptr), tail(nullptr), list_size(0) {
  for (const auto& item : items) {
    this->push_back(item);
  }
}

template <typename T>
list<T>::list(const list& l) : list() {
  *this = l;
}

template <typename T>
list<T>::list(list&& l) : list() {
  this->swap(l);
}

template <typename T>
list<T>::~list() {
  clear();
}

template <typename T>
list<T>& list<T>::operator=(list&& other) {
  this->swap(other);
  return *this;
}

template <typename T>
list<T>& list<T>::operator=(const list& other) {
  if (this == &other) return *this;
  this->clear();
  list_size = 0;
  for (Node* it = other.head; it != nullptr; it = it->next) {
    push_back(it->data);
  }
  return *this;
}

template <typename T>
typename list<T>::const_reference list<T>::front() {
  if (size() == 0) {
    throw "out_of_range";
  }
  return head->data;
}

template <typename T>
typename list<T>::const_reference list<T>::back() {
  if (size() == 0) {
    throw "out_of_range";
  }
  return tail->data;
}

template <typename T>
bool list<T>::empty() {
  return !list_size;
}

template <typename T>
typename list<T>::size_type list<T>::size() {
  return list_size;
}

template <typename T>
typename list<T>::size_type list<T>::max_size() {
  return std::numeric_limits<size_type>::max() / sizeof(Node) / 2;
}

template <typename T>
void list<T>::clear() {
  while (head) {
    Node* next = head->next;
    delete head;
    head = next;
  }
  tail = nullptr;
  list_size = 0;
}

template <typename T>
typename list<T>::iterator list<T>::insert(iterator pos,
                                           const_reference value) {
  Node* tmp = pos.n_current;
  Node* newNode = new Node(value);

  if (!head) {
    // Пустой список
    head = tail = newNode;
    push_back(value);
  } else if (tmp == tail) {
    // Вставка в конец
    push_back(value);
    delete newNode;
    return iterator(tail);
  } else if (tmp == head) {
    // Вставка в начало
    push_front(value);
    delete newNode;
    return iterator(head);
  } else {
    // Вставка в середину
    newNode->next = tmp;
    newNode->prev = tmp->prev;
    if (tmp->prev) {
      tmp->prev->next = newNode;
    }
    tmp->prev = newNode;
    list_size++;
  }
  return iterator(newNode);
}

template <typename T>
void list<T>::erase(iterator pos) {
  Node* tmp = pos.n_current;

  if (tmp == nullptr) {
    throw "out_of_range";
  }

  if (tmp == head) {
    // Удаление головы
    head = head->next;
    if (head) {
      head->prev = nullptr;
    } else {
      tail = nullptr;  // Список пуст
    }
  } else {
    if (tmp == tail) {
      // Удаление хвоста
      tail = tail->prev;
      tail->next = nullptr;
    } else {
      // Удаление из середины
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
    }
  }

  delete tmp;
  list_size--;
}

template <typename T>
void list<T>::push_back(const_reference value) {
  Node* newNode = new Node(value);
  if (!head) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
  list_size++;
}

template <typename T>
void list<T>::pop_back() {
  if (list_size == 0) {
    throw "out_of_range";
  }
  Node* oldTail = tail;
  if (head == tail) {  // Один элемент
    head = tail = nullptr;
  } else {
    tail = tail->prev;
    tail->next = nullptr;
  }
  delete oldTail;
  list_size--;
}

template <typename T>
void list<T>::push_front(const_reference value) {
  Node* newNode = new Node(value);
  if (!head) {
    head = tail = newNode;
  } else {
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
  }
  list_size++;
}

template <typename T>
void list<T>::pop_front() {
  if (list_size == 0) {
    throw "out_of_range";
  }
  Node* oldHead = head;
  if (head == tail) {  // Один элемент
    head = tail = nullptr;
  } else {
    head = head->next;
    head->prev = nullptr;
  }
  delete oldHead;
  list_size--;
}

template <typename T>
void list<T>::swap(list& other) {
  std::swap(head, other.head);
  std::swap(tail, other.tail);
  std::swap(list_size, other.list_size);
}

template <typename T>
void list<T>::merge(list& other) {
  // Временный узел от которого пойдет результирующий список
  Node* dummy = new Node(value_type());
  Node* tail = dummy;

  // Указалетели на головы списков
  Node* first = head;
  Node* second = other.head;

  // Перебор двух сортированных списков в один
  while (first != nullptr && second != nullptr) {
    if (first->data <= second->data) {
      tail->next = first;
      first->prev = tail;
      first = first->next;
    } else {
      tail->next = second;
      second->prev = tail;
      second = second->next;
    }
    tail = tail->next;
  }

  // Добавление оставшихся элементов (если есть)
  tail->next = (first != nullptr) ? first : second;
  if (tail->next) {
    tail->next->prev = tail;
  }

  // Обновление указателей head и tail для this
  head = dummy->next;
  if (head) {
    head->prev = nullptr;
  }
  while (tail->next != nullptr) {
    tail = tail->next;
  }
  this->tail = tail;

  // Очистка списка other
  other.head = other.tail = nullptr;
  other.list_size = 0;
  delete dummy;
}

template <typename T>
void list<T>::splice(const_iterator pos, list& other) {
  iterator tmp = pos;
  iterator it = other.begin();
  for (size_t i = 0; i < other.size(); ++i) {
    tmp = insert(tmp, *it);
    ++tmp;
    ++it;
  }
  other.clear();
}

template <typename T>
void list<T>::reverse() {
  Node* current = head;
  Node* temp = nullptr;

  while (current != nullptr) {
    temp = current->prev;
    current->prev = current->next;
    current->next = temp;
    current = current->prev;
  }

  if (temp != nullptr) {
    head = temp->prev;
  }
}

template <typename T>
void list<T>::unique() {
  if (!head) {
    throw "out_of_range";
  }

  Node* current = head;
  while (current != nullptr && current->next != nullptr) {
    if (current->data == current->next->data) {
      Node* duplicate = current->next;
      current->next = duplicate->next;
      if (duplicate->next) {
        duplicate->next->prev = current;
      } else {
        tail = current;
      }
      delete duplicate;
      list_size--;
    } else {
      current = current->next;
    }
  }
}

template <typename T>
void list<T>::sort() {
  // Oleg
  iterator iter = begin();
  iterator iter2 = begin();
  iter2++;
  while (iter2.n_current != nullptr) {
    if (iter2.n_current->data >= iter.n_current->data) {
      iter++;
      iter2++;
    } else {
      insert(iter, iter2.n_current->data);
      erase(iter2);
      iter = begin();
      iter2 = begin();
      iter2++;
    }
  }
}

template <typename T>
typename list<T>::Node* list<T>::merge(Node* left, Node* right) {
  if (!left) return right;
  if (!right) return left;

  if (left->data < right->data) {
    left->next = merge(left->next, right);
    left->next->prev = left;
    left->prev = nullptr;
    return left;
  } else {
    right->next = merge(left, right->next);
    right->next->prev = right;
    right->prev = nullptr;
    return right;
  }
}

template <typename T>
template <class... Args>
typename list<T>::ListIterator list<T>::emplace(const_iterator pos,
                                                Args&&... args) {
  return insert(pos, T(args...));
}

template <typename T>
template <class... Args>
void list<T>::emplace_back(Args&&... args) {
  push_back(T(args...));
}

template <typename T>
template <class... Args>
void list<T>::emplace_front(Args&&... args) {
  push_front(T(args...));
}

}  // namespace s21
#endif

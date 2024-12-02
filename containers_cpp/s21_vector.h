#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <initializer_list>
namespace s21 {
template <typename T>
class vector {
 public:
  // Переопределение имён типов (для удобства восприятия):
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Constructors
  vector(void) : size_(0), capacity_(0), data_(nullptr){};
  vector(size_type n) : size_(n), capacity_(n) {
    (n > 0) ? data_ = new value_type[n]() : data_ = nullptr;
  }
  vector(std::initializer_list<value_type> const &items) : vector() {
    for (const auto &item : items) {
      push_back(item);
    }
  }
  vector(const vector &v) : size_(v.size_), capacity_(v.capacity_) {
    data_ = new value_type[capacity_]();
    for (size_type i = 0; i < size_; i++) {
      data_[i] = v.data_[i];
    }
  }
  vector(vector &&v) : size_(v.size_), capacity_(v.capacity_), data_(v.data_) {
    v.data_ = nullptr;
    v.capacity_ = 0;
    v.size_ = 0;
  }
  ~vector(void) { delete[] data_; }

  // Перегрузка оператора перемещениия
  vector &operator=(vector &&v) {
    if (&v != this) {
      this->~vector();
      size_ = v.size_;
      capacity_ = v.capacity_;
      data_ = v.data_;
      v.size_ = 0;
      v.capacity_ = 0;
      v.data_ = nullptr;
    }
    return *this;
  }

  // Accessors
  // доступ к элементу с проверкой границ
  reference at(size_type pos) { return (pos < size_) ? data_[pos] : throw ""; }
  // доступ к элементу без проверки границ
  reference operator[](size_type pos) { return data_[pos]; }
  // доступ к первому элементу
  const_reference front() { return data_[0]; }
  // к последнему элементу
  const_reference back() { return data_[size_ - 1]; }
  // прямой доступ к базовому массиву
  T *data() { return data_; }

  // Методы для итерирования по элементам класса (доступ к итераторам):
  iterator begin() { return data_; }
  iterator end() { return data_ + size_; };

  // ASSIGN INFO:
  bool empty() { return size_ ? false : true; }
  size_type size() { return size_; }
  size_type max_size() const {
    return std::numeric_limits<size_type>::max() / (sizeof(value_type) * 2);
  }
  void reserve(size_type size) {
    if (size > capacity_) {
      realloc(size);
    }
  }
  size_type capacity() { return capacity_; }
  void shrink_to_fit() { realloc(size_); }

  // Mutators:
  void clear() { size_ = 0; }

  iterator insert(iterator pos, const_reference value) {
    int diff = pos - begin();
    if (size_ == capacity_) {
      realloc(capacity_ * 2);
    }
    if (capacity_ == 0) {
      this->reserve(1);
    }
    for (int i = size_; i > diff; i--) {
      data_[i] = data_[i - 1];
    }
    data_[diff] = value;
    size_++;
    return data_ + diff;
  }

  void erase(iterator pos) {
    for (size_type i = pos - begin(); i < size_; i++) {
      data_[i] = data_[i + 1];
    }
    size_--;
  }

  void push_back(const_reference value) {
    if (size_ == capacity_) {
      realloc(capacity_ * 2);
    }
    if (capacity_ == 0) {
      this->reserve(1);
    }
    data_[size_] = value;
    size_++;
  }

  void pop_back() { size_--; }

  void swap(vector &other) {
    size_type buf_size = size_, buf_capacity = capacity_;
    size_ = other.size_;
    capacity_ = other.capacity_;
    other.size_ = buf_size;
    other.capacity_ = buf_capacity;
    for (size_type i = 0; i < size_; i++) {
      value_type buff = data_[i];
      data_[i] = other.data_[i];
      other.data_[i] = buff;
    }
  }

  void realloc(size_type new_size) {
    vector buff = std::move(*this);
    size_ = buff.size_;
    capacity_ = new_size;
    data_ = new value_type[capacity_]();
    for (size_type i = 0; i < size_; i++) {
      data_[i] = buff.data_[i];
    }
  }
  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (push_back(std::forward<Args>(args)), ...);
  }
  template <typename const_iterator, typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args) {
    vector buff_vec;
    (buff_vec.insert_many_back(args), ...);
    int diff = pos - begin();
    iterator buff_link = begin() + diff;
    for (int i = buff_vec.size() - 1; i >= 0; i--) {
      buff_link = insert(buff_link, buff_vec[i]);
    }
    iterator ret_link = begin() + diff;
    return ret_link;
  }

 private:
  size_type size_, capacity_;
  T *data_;
};
}  // namespace s21
#endif

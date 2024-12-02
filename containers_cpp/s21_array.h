#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <initializer_list>
namespace s21 {
template <typename T, const size_t Arr_size>
class array {
 public:
  // Переопределение имён типов (для удобства восприятия):
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Constructors
  array(void) {
    if (Arr_size > 0) {
      size_ = Arr_size;
      data_ = new value_type[Arr_size]();
    } else {
      size_ = 0;
      data_ = nullptr;
    }
  }
  array(std::initializer_list<value_type> const &items) {
    if (items.size() > 0) {
      data_ = new value_type[items.size()]();
      int i = 0;
      for (const auto &item : items) {
        data_[i] = item;
        i++;
      }
    }
  }
  array(const array &v) : size_(v.size_) {
    data_ = new value_type[size_]();
    for (size_type i = 0; i < size_; i++) {
      data_[i] = v.data_[i];
    }
  }
  array(array &&v) : size_(v.size_), data_(v.data_) {
    v.data_ = nullptr;
    v.size_ = 0;
  }
  ~array(void) { delete[] data_; }

  // Перегрузка оператора перемещениия
  array &operator=(array &&v) {
    if (&v != this) {
      this->~array();
      size_ = v.size_;
      data_ = v.data_;
      v.size_ = 0;
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
  size_type max_size() const { return size_; }

  // Mutators:
  void swap(array &other) {
    size_type buf_size = size_;
    size_ = other.size_;
    other.size_ = buf_size;
    for (size_type i = 0; i < size_; i++) {
      value_type buff = data_[i];
      data_[i] = other.data_[i];
      other.data_[i] = buff;
    }
  }
  void fill(const_reference value) {
    for (size_type i = 0; i < size_; i++) {
      data_[i] = value;
    }
  }

 private:
  size_type size_;
  T *data_;
};
}  // namespace s21
#endif

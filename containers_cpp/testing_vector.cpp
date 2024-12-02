#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "s21_containers.h"

TEST(ALL_VECTOR, constructor_default) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector;
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.data(), original_vector.data());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_EQ(my_fake_vector.data(), nullptr);
}

TEST(ALL_VECTOR, constructor_default_n) {
  s21::vector<int> my_fake_vector(99);
  std::vector<int> original_vector(99);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_NE(original_vector.data(), nullptr);
  EXPECT_NE(my_fake_vector.data(), nullptr);
  EXPECT_EQ(my_fake_vector.capacity(), 99);
  EXPECT_EQ(my_fake_vector.size(), 99);
}

TEST(ALL_VECTOR, constructor_init_list) {
  std::initializer_list<int> temp = {2, 4, 6, 8, 8, 6, 4, 2};
  std::vector<int> original_vector(temp);
  s21::vector<int> my_fake_vector(temp);
  EXPECT_NE(original_vector.data(), nullptr);
  EXPECT_NE(my_fake_vector.data(), nullptr);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  for (size_t i = 0; i < temp.size(); i++) {
    EXPECT_EQ(my_fake_vector[i], original_vector[i]);
  }
}

TEST(ALL_VECTOR, constructor_copy) {
  s21::vector<int> temp(99);
  s21::vector<int> my_fake_vector(temp);
  std::vector<int> original_vector(99);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_NE(original_vector.data(), nullptr);
  EXPECT_NE(my_fake_vector.data(), nullptr);
  EXPECT_EQ(my_fake_vector.capacity(), 99);
  EXPECT_EQ(my_fake_vector.size(), 99);
}

TEST(ALL_VECTOR, constructor_move) {
  s21::vector<int> temp(99);
  s21::vector<int> my_fake_vector(std::move(temp));
  std::vector<int> original_vector(99);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_NE(original_vector.data(), nullptr);
  EXPECT_NE(my_fake_vector.data(), nullptr);
  EXPECT_EQ(my_fake_vector.capacity(), 99);
  EXPECT_EQ(my_fake_vector.size(), 99);
  EXPECT_EQ(temp.size(), 0);
  EXPECT_NE(my_fake_vector.size(), temp.size());
  EXPECT_EQ(temp.capacity(), 0);
  EXPECT_NE(my_fake_vector.capacity(), temp.capacity());
  EXPECT_EQ(temp.data(), nullptr);
}

TEST(ALL_VECTOR, overload_move) {
  s21::vector<int> temp(99);
  s21::vector<int> my_fake_vector = std::move(temp);
  std::vector<int> original_vector(99);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_NE(original_vector.data(), nullptr);
  EXPECT_NE(my_fake_vector.data(), nullptr);
  EXPECT_EQ(my_fake_vector.capacity(), 99);
  EXPECT_EQ(my_fake_vector.size(), 99);
  EXPECT_EQ(temp.size(), 0);
  EXPECT_NE(my_fake_vector.size(), temp.size());
  EXPECT_EQ(temp.capacity(), 0);
  EXPECT_NE(my_fake_vector.capacity(), temp.capacity());
  EXPECT_EQ(temp.data(), nullptr);
}

TEST(ALL_VECTOR, at) {
  s21::vector<int> my_fake_vector(1);
  std::vector<int> original_vector(1);
  EXPECT_EQ(my_fake_vector.at(0), original_vector.at(0));
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  my_fake_vector.at(0) = 66;
  original_vector.at(0) = 99;
  EXPECT_NE(my_fake_vector[0], original_vector[0]);
  EXPECT_ANY_THROW(my_fake_vector.at(1));
  EXPECT_ANY_THROW(original_vector.at(1));
}

TEST(ALL_VECTOR, overload_accessor) {
  s21::vector<int> my_fake_vector(1);
  std::vector<int> original_vector(1);
  EXPECT_EQ(my_fake_vector[0], original_vector[0]);
  original_vector[0] = 99;
  my_fake_vector[0] = 66;
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_NE(my_fake_vector[0], original_vector[0]);
}

TEST(ALL_VECTOR, front) {
  s21::vector<int> my_fake_vector(1);
  std::vector<int> original_vector(1);
  EXPECT_EQ(my_fake_vector.front(), original_vector[0]);
  original_vector.front() = 99;
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_NE(my_fake_vector.front(), original_vector[0]);
}

TEST(ALL_VECTOR, back) {
  s21::vector<int> my_fake_vector(1);
  std::vector<int> original_vector(1);
  EXPECT_EQ(my_fake_vector.back(), original_vector[0]);
  original_vector.back() = 99;
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_NE(my_fake_vector.back(), original_vector[0]);
}

TEST(ALL_VECTOR, data) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector;
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.data(), original_vector.data());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_EQ(my_fake_vector.data(), nullptr);
}

TEST(ALL_VECTOR, begin) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector;
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_EQ(my_fake_vector.begin(), nullptr);
  my_fake_vector.push_back(66);
  EXPECT_NE(my_fake_vector.begin(), nullptr);
}

TEST(ALL_VECTOR, end) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector;
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_EQ(my_fake_vector.end(), nullptr);
  my_fake_vector.push_back(66);
  EXPECT_NE(my_fake_vector.end(), nullptr);
}

TEST(ALL_VECTOR, empty) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector;
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_EQ(my_fake_vector.empty(), true);
  EXPECT_EQ(original_vector.empty(), true);
  my_fake_vector.push_back(66);
  EXPECT_NE(my_fake_vector.empty(), true);
  original_vector.push_back(99);
  EXPECT_NE(original_vector.empty(), true);
}

TEST(ALL_VECTOR, size) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector;
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  my_fake_vector.push_back(66);
  EXPECT_NE(my_fake_vector.size(), original_vector.size());
}

TEST(ALL_VECTOR, max_size) {
  s21::vector<int> m0;
  std::vector<int> o0;
  EXPECT_EQ(m0.max_size(), o0.max_size());
  s21::vector<double> m1;
  std::vector<double> o1;
  EXPECT_EQ(m1.max_size(), o1.max_size());
  s21::vector<long long> m2;
  std::vector<long long> o2;
  EXPECT_EQ(m2.max_size(), o2.max_size());
  s21::vector<int> m01(10000);
  std::vector<int> o01(10000);
  EXPECT_EQ(m01.max_size(), o01.max_size());
}

TEST(ALL_VECTOR, reserve) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector;
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  my_fake_vector.reserve(3);
  EXPECT_NE(my_fake_vector.capacity(), original_vector.capacity());
  original_vector.reserve(3);
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
}

TEST(ALL_VECTOR, capacity) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector;
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  my_fake_vector.reserve(7);
  EXPECT_NE(my_fake_vector.capacity(), original_vector.capacity());
  original_vector.reserve(7);
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
}

TEST(ALL_VECTOR, shrink_to_fit) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector;
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  my_fake_vector.reserve(7);
  EXPECT_NE(my_fake_vector.capacity(), original_vector.capacity());
  my_fake_vector.shrink_to_fit();
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
}

TEST(ALL_VECTOR, clear) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector;
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  my_fake_vector.push_back(7);
  original_vector.push_back(7);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  my_fake_vector.clear();
  original_vector.clear();
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
}

TEST(ALL_VECTOR, insert) {
  s21::vector<int> my_fake_vector(10);
  std::vector<int> original_vector(10);
  my_fake_vector.reserve(11);
  original_vector.reserve(11);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_EQ(*(my_fake_vector.begin() + 4), *(original_vector.begin() + 4));
  my_fake_vector.insert(my_fake_vector.begin() + 4, 4444);
  original_vector.insert(original_vector.begin() + 4, 4444);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_EQ(*(my_fake_vector.begin() + 4), *(original_vector.begin() + 4));
}

TEST(ALL_VECTOR, erase) {
  s21::vector<int> my_fake_vector(6);
  std::vector<int> original_vector(6);
  my_fake_vector[5] = 97;
  original_vector[5] = 97;
  EXPECT_EQ(my_fake_vector.at(5), 97);
  EXPECT_EQ(my_fake_vector.at(5), original_vector.at(5));
  my_fake_vector.erase(my_fake_vector.end() - 1);
  original_vector.erase(original_vector.end() - 1);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
}

TEST(ALL_VECTOR, push_back) {
  s21::vector<int> my_fake_vector(6);
  std::vector<int> original_vector(6);
  my_fake_vector.push_back(5);
  original_vector.push_back(5);
  EXPECT_EQ(my_fake_vector.at(6), 5);
  EXPECT_EQ(my_fake_vector.at(6), original_vector.at(6));
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
}

TEST(ALL_VECTOR, pop_back) {
  s21::vector<int> my_fake_vector(6);
  std::vector<int> original_vector(6);
  EXPECT_EQ(my_fake_vector.at(5), 0);
  EXPECT_EQ(my_fake_vector.at(5), original_vector.at(5));
  my_fake_vector.pop_back();
  original_vector.pop_back();
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  EXPECT_ANY_THROW(my_fake_vector.at(5));
  EXPECT_ANY_THROW(original_vector.at(5));
}

TEST(ALL_VECTOR, swap) {
  s21::vector<int> my_fake(3);
  std::vector<int> original(3);
  my_fake[2] = 99;
  original[2] = 99;
  s21::vector<int> my_fake_vector(6);
  std::vector<int> original_vector(6);
  EXPECT_EQ(my_fake_vector.at(4), 0);
  EXPECT_EQ(my_fake_vector.at(4), original_vector.at(4));
  EXPECT_EQ(my_fake_vector.size(), 6);
  EXPECT_EQ(my_fake_vector.capacity(), 6);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
  my_fake_vector.swap(my_fake);
  original_vector.swap(original);
  EXPECT_ANY_THROW(my_fake_vector.at(4));
  EXPECT_ANY_THROW(original_vector.at(4));
  EXPECT_EQ(my_fake_vector.size(), 3);
  EXPECT_EQ(my_fake_vector.capacity(), 3);
  EXPECT_EQ(my_fake_vector.size(), original_vector.size());
  EXPECT_EQ(my_fake_vector.capacity(), original_vector.capacity());
}

TEST(ALL_VECTOR, remains_push_back) {
  s21::vector<int> my_fake_vector(6);
  std::vector<int> original_vector(6);
  my_fake_vector.reserve(10);
  original_vector.reserve(10);
  my_fake_vector.push_back(7);
  original_vector.push_back(7);
  EXPECT_EQ(my_fake_vector.at(6), original_vector.at(6));
}

TEST(ALL_VECTOR, remains_insert) {
  s21::vector<int> my_fake_vector(6);
  std::vector<int> original_vector(6);
  my_fake_vector.insert(my_fake_vector.begin(), 7);
  original_vector.insert(original_vector.begin(), 7);
  EXPECT_EQ(my_fake_vector.at(6), original_vector.at(6));
  s21::vector<int> my_fake_vector2;
  my_fake_vector2.insert(my_fake_vector2.begin(), 7);
  EXPECT_EQ(my_fake_vector2[0], 7);
}

TEST(ALL_VECTOR, remains_reserve) {
  s21::vector<int> my_fake_vector(6);
  std::vector<int> original_vector(6);
  my_fake_vector.reserve(5);
  original_vector.reserve(5);
  EXPECT_EQ(my_fake_vector.at(5), original_vector.at(5));
}

TEST(ALL_VECTOR, remains_insert_many_back) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector = {2, 3, 7, 8, 9};
  my_fake_vector.insert_many_back(2, 3, 7, 8, 9);
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(my_fake_vector[i], original_vector[i]);
  }
}

TEST(ALL_VECTOR, remains_insert_many) {
  s21::vector<int> my_fake_vector;
  std::vector<int> original_vector = {2, 3, 7, 8, 9};
  my_fake_vector.insert_many(my_fake_vector.begin(), 2, 3, 7, 8, 9);
  for (size_t i = 0; i < my_fake_vector.size(); i++) {
    EXPECT_EQ(my_fake_vector[i], original_vector[i]);
  }
}

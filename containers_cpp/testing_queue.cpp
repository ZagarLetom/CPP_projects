#include <gtest/gtest.h>

#include "s21_containers.h"

TEST(Constructor_QUEUE, def_const) {
  s21::queue<int> q1({1, 2, 3, 4, 5});
  s21::queue<int> q2 = q1;
  s21::queue<int> q3(std::move(q1));
  s21::queue<int> q4;
  q4 = std::move(q3);
}
TEST(Methods_QUEUE, pop_push) {
  s21::queue<int> q1({1, 2, 3, 4, 5});
  EXPECT_EQ(5, q1.back());
  EXPECT_EQ(1, q1.front());
  q1.pop();
  EXPECT_EQ(2, q1.front());
  q1.push(100);
  EXPECT_EQ(100, q1.back());
}

TEST(Methods_QUEUE, pop_back_front_throw) {
  s21::queue<int> q1({1, 2, 3});
  q1.pop();
  q1.pop();
  q1.pop();
  EXPECT_ANY_THROW(q1.pop());
  EXPECT_ANY_THROW(q1.back());
  EXPECT_ANY_THROW(q1.front());
}

TEST(Methods_QUEUE, size) {
  s21::queue<int> q1({1, 2, 3, 4, 5});
  EXPECT_EQ(5, q1.size());
}

TEST(Methods_QUEUE, swap) {
  s21::queue<int> q1({1, 2, 3, 4, 5});
  s21::queue<int> q2({5, 4, 3, 2, 1});
  EXPECT_EQ(5, q1.back());
  q1.swap(q2);
  EXPECT_EQ(1, q1.back());
  EXPECT_EQ(q2.front(), q1.back());
  EXPECT_EQ(q1.front(), q2.back());
}

TEST(Methods_QUEUE, insert_many_back) {
  s21::queue<int> q1({1, 2});
  q1.insert_many_back(3, 4, 5, 6);
  EXPECT_EQ(6, q1.back());
  EXPECT_EQ(1, q1.front());
}

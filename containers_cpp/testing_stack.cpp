#include <gtest/gtest.h>

#include <iostream>
#include <stack>

#include "s21_containers.h"

TEST(ALL_STACK, constructor_default) {
  s21::stack<int> my_fake_stack;
  std::stack<int> original_stack;
  EXPECT_EQ(my_fake_stack.size(), original_stack.size());
  EXPECT_EQ(my_fake_stack.empty(), original_stack.empty());
}
TEST(ALL_STACK, constructor_initializer_list) {
  std::initializer_list<int> temp{995, 996, 997, 998, 999, 1000};
  s21::stack<int> my_fake_stack(temp);
  std::stack<int> original_stack(temp);
  EXPECT_EQ(my_fake_stack.size(), original_stack.size());
  for (size_t i = 0; i < original_stack.size(); i++) {
    EXPECT_EQ(my_fake_stack.top(), original_stack.top());
  }
}

TEST(ALL_STACK, constructor_copy) {
  std::initializer_list<int> temp{1, 2, 77, 4, 5};
  s21::stack<int> my_fake_stack(temp);
  s21::stack<int> my_fake_stack_2(my_fake_stack);
  EXPECT_EQ(my_fake_stack.size(), my_fake_stack_2.size());
  while (!my_fake_stack.empty()) {
    EXPECT_EQ(my_fake_stack.top(), my_fake_stack_2.top());
    my_fake_stack.pop();
    my_fake_stack_2.pop();
  }
}

TEST(ALL_STACK, constructor_move) {
  std::initializer_list<int> temp{14, 15, 50, 11, 7, 2024};
  s21::stack<int> my_fake_stack(temp);
  s21::stack<int> my_fake_stack_2(std::move(my_fake_stack));
  std::stack<int> original_stack(temp);
  std::stack<int> original_stack_2(std::move(original_stack));
  EXPECT_EQ(my_fake_stack_2.size(), original_stack_2.size());
  while (!my_fake_stack_2.empty()) {
    EXPECT_EQ(my_fake_stack_2.top(), original_stack_2.top());
    my_fake_stack_2.pop();
    original_stack_2.pop();
  }
}

TEST(ALL_STACK, overload_move) {
  std::initializer_list<int> temp{14, 15, 50, 11, 7, 2024};
  s21::stack<int> my_fake_stack(temp);
  s21::stack<int> my_fake_stack_2;
  std::stack<int> original_stack(temp);
  std::stack<int> original_stack_2;
  my_fake_stack_2 = std::move(my_fake_stack);
  original_stack_2 = std::move(original_stack);
  EXPECT_EQ(my_fake_stack_2.size(), original_stack_2.size());
  while (!original_stack_2.empty()) {
    EXPECT_EQ(my_fake_stack_2.top(), original_stack_2.top());
    my_fake_stack_2.pop();
    original_stack_2.pop();
  }
}

TEST(ALL_STACK, push) {
  s21::stack<int> my_fake_stack;
  std::stack<int> my_fake_stack_2;
  my_fake_stack.push(7);
  my_fake_stack.push(9);
  my_fake_stack.push(79);
  my_fake_stack_2.push(7);
  my_fake_stack_2.push(9);
  my_fake_stack_2.push(79);
  EXPECT_EQ(my_fake_stack.size(), my_fake_stack_2.size());
  while (!my_fake_stack_2.empty()) {
    EXPECT_EQ(my_fake_stack.top(), my_fake_stack_2.top());
    my_fake_stack.pop();
    my_fake_stack_2.pop();
  }
}

TEST(ALL_STACK, swap) {
  s21::stack<int> my_fake_stack({1, 2, 3, 4, 5});
  std::stack<int> my_fake_stack_2({1, 2, 3, 4, 5});
  s21::stack<int> original_stack({11, 12, 13, 14, 15});
  std::stack<int> original_stack_2({11, 12, 13, 14, 15});
  my_fake_stack.swap(original_stack);
  my_fake_stack_2.swap(original_stack_2);
  EXPECT_EQ(my_fake_stack.size(), my_fake_stack_2.size());
  while (!my_fake_stack.empty()) {
    EXPECT_EQ(my_fake_stack.top(), my_fake_stack_2.top());
    my_fake_stack.pop();
    my_fake_stack_2.pop();
  }
}

TEST(ALL_STACK, pop) {
  s21::stack<int> my_fake_stack;
  std::stack<int> original_stack;
  EXPECT_EQ(my_fake_stack.size(), original_stack.size());
  my_fake_stack.push(99);
  original_stack.push(99);
  EXPECT_EQ(my_fake_stack.size(), original_stack.size());
  my_fake_stack.push(993);
  original_stack.push(993);
  EXPECT_EQ(my_fake_stack.size(), original_stack.size());
  my_fake_stack.pop();
  EXPECT_NE(my_fake_stack.size(), original_stack.size());
}

TEST(ALL_STACK, insert_many_front) {
  s21::stack<int> my_fake_stack;
  std::stack<int> my_fake_stack_2;
  my_fake_stack.insert_many_front(464);
  my_fake_stack_2.emplace(464);
  EXPECT_EQ(my_fake_stack.size(), my_fake_stack_2.size());
  EXPECT_EQ(my_fake_stack.top(), my_fake_stack_2.top());
}

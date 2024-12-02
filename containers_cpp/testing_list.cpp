#include <gtest/gtest.h>

#include <iostream>
#include <iterator>
#include <list>

#include "s21_containers.h"

TEST(list_constructor_suit, default_constructor) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  ASSERT_EQ(s21list.empty(), stdlist.empty());
  ASSERT_EQ(s21list.size(), stdlist.size());
}

TEST(list_constructor_suit, size_constructor) {
  s21::list<int> s21list(5);
  std::list<int> stdlist(5);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_constructor_suit, init_constructor) {
  s21::list<int> s21list{66, 44, 0, 97};
  std::list<int> stdlist{66, 44, 0, 97};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_constructor_suit, init_char_constructor) {
  s21::list<char> s21list{'J', 'o', 'h', 'n'};
  std::list<char> stdlist{'J', 'o', 'h', 'n'};
  s21::list<char>::iterator s21it = s21list.begin();
  std::list<char>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_constructor_suit, init_string_constructor) {
  s21::list<std::string> s21list{"aannemar", "rdontos", "tsherman"};
  std::list<std::string> stdlist{"aannemar", "rdontos", "tsherman"};
  s21::list<std::string>::iterator s21it = s21list.begin();
  std::list<std::string>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_constructor_suit, copy_constructor) {
  s21::list<int> s21list{66, 44, 0, 97};
  std::list<int> stdlist{66, 44, 0, 97};
  s21::list<int> s21list2(s21list);
  std::list<int> stdlist2(stdlist);
  s21::list<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_constructor_suit, move_constructor) {
  s21::list<int> s21list{66, 44, 0, 97};
  std::list<int> stdlist{66, 44, 0, 97};
  s21::list<int> s21list2(std::move(s21list));
  std::list<int> stdlist2(std::move(stdlist));
  s21::list<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_constructor_suit, move_operator_constructor) {
  s21::list<int> s21list{66, 44, 0, 97};
  std::list<int> stdlist{66, 44, 0, 97};
  s21::list<int> s21list2 = std::move(s21list);
  std::list<int> stdlist2 = std::move(stdlist);
  s21::list<int>::iterator s21it = s21list2.begin();
  std::list<int>::iterator stdit = stdlist2.begin();
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_front_back, front_back) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  ASSERT_ANY_THROW(s21list.front());
  ASSERT_ANY_THROW(s21list.back());
  s21list.push_front(66);
  s21list.push_back(66);
  s21list.push_back(21212);
  stdlist.push_front(66);
  stdlist.push_back(66);
  stdlist.push_back(21212);
  ASSERT_EQ(s21list.front(), stdlist.front());
  ASSERT_EQ(s21list.back(), stdlist.back());
}

TEST(list_empty_clear, empty_clear) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(66);
  s21list.push_back(66);
  s21list.push_back(21212);
  stdlist.push_front(66);
  stdlist.push_back(66);
  stdlist.push_back(21212);
  s21list.clear();
  stdlist.clear();
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list.empty(), stdlist.empty());
}

TEST(list_push_pop_suit, push) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  s21list.push_front(66);
  s21list.push_back(66);
  s21list.push_back(21212);
  stdlist.push_front(66);
  stdlist.push_back(66);
  stdlist.push_back(21212);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_push_pop_suit, pop_empty) {
  s21::list<int> s21list;
  std::list<int> stdlist{10};
  ASSERT_ANY_THROW(s21list.pop_back());
  ASSERT_ANY_THROW(s21list.pop_front());
  s21list.push_back(10);
  s21list.pop_back();
  stdlist.pop_back();
  ASSERT_EQ(s21list.empty(), stdlist.empty());
  s21list.push_back(10);
  stdlist.push_back(10);
  s21list.pop_front();
  stdlist.pop_front();
  ASSERT_EQ(s21list.empty(), stdlist.empty());
}

TEST(list_push_pop_suit, pop) {
  s21::list<int> s21list{66, 44, 0, 97};
  std::list<int> stdlist{66, 44, 0, 97};
  s21list.pop_back();
  stdlist.pop_back();
  ASSERT_EQ(s21list.front(), stdlist.front());
  ASSERT_EQ(s21list.back(), stdlist.back());
  s21list.pop_front();
  stdlist.pop_front();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  s21list.clear();
  stdlist.clear();
  ASSERT_EQ(s21list.empty(), stdlist.empty());
}

TEST(list_function_suit, insert_empty) {
  s21::list<int> s21list;
  std::list<int> stdlist;
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.insert(s21it, 1);
  stdlist.insert(stdit, 1);
  ASSERT_EQ(s21list.front(), stdlist.front());
}

TEST(list_function_suit, insert) {
  s21::list<int> s21list{66, 44, 0, 97};
  std::list<int> stdlist{66, 44, 0, 97};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.insert(s21it, 66);
  stdlist.insert(stdit, 66);
  ASSERT_EQ(s21list.front(), stdlist.front());
  ++s21it;
  ++stdit;
  s21list.insert(s21it, 2142);
  stdlist.insert(stdit, 2142);
  s21it = s21list.end();
  stdit = stdlist.end();
  s21list.insert(s21it, 69);
  stdlist.insert(stdit, 69);
  s21it = s21list.begin();
  stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_function_suit, erase_back) {
  s21::list<int> s21list{1, 3};
  s21::list<int> stdlist{1, 3};
  s21::list<int>::iterator s21it = s21list.end();
  s21::list<int>::iterator stdit = stdlist.end();
  s21list.erase(s21it);
  stdlist.erase(stdit);
  ASSERT_EQ(s21list.front(), stdlist.front());
  s21it = s21list.begin();
  stdit = stdlist.begin();
  s21list.erase(s21it);
  stdlist.erase(stdit);
  ASSERT_EQ(s21list.size(), stdlist.size());
}

TEST(list_function_suit, erase_null) {
  s21::list<int> s21list{1};
  s21::list<int> stdlist{1};
  s21::list<int>::iterator s21it = s21list.begin();
  s21::list<int>::iterator stdit = stdlist.begin();
  s21list.erase(s21it);
  stdlist.erase(stdit);
  ASSERT_EQ(s21list.size(), stdlist.size());
}

TEST(list_function_suit, erase_empty) {
  s21::list<int> s21list{66, 44, 0, 97};
  s21::list<int>::iterator s21it = s21list.begin();
  s21it--;
  ASSERT_ANY_THROW(s21list.erase(s21it));
}

TEST(list_function_suit, erase) {
  s21::list<int> s21list{66, 44, 0, 97};
  std::list<int> stdlist{66, 44, 0, 97};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.erase(s21it);
  stdlist.erase(stdit);
  ASSERT_EQ(s21list.front(), stdlist.front());
  s21it = s21list.begin();
  stdit = stdlist.begin();
  ++s21it;
  ++stdit;
  s21list.erase(s21it);
  stdlist.erase(stdit);
  s21it = s21list.begin();
  stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_function_suit, swap) {
  s21::list<int> s21list{66, 44, 0, 97, 2142};
  s21::list<int> s21list2{5, 3};
  std::list<int> stdlist{66, 44, 0, 97, 2142};
  std::list<int> stdlist2{5, 3};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.swap(s21list2);
  stdlist.swap(stdlist2);
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_function_suit, merge) {
  s21::list<int> s21list{66, 44, 0, 97, 2142};
  s21::list<int> s21list2{5, 3};
  std::list<int> stdlist{66, 44, 0, 97, 2142};
  std::list<int> stdlist2{5, 3};
  s21list.merge(s21list2);
  stdlist.merge(stdlist2);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size() + 2, stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  ASSERT_EQ(s21list2.empty(), stdlist2.empty());
}

TEST(list_function_suit, merge_2) {
  s21::list<int> s21list2{66, 44, 0, 97, 2142};
  s21::list<int> s21list{5, 3};
  std::list<int> stdlist2{66, 44, 0, 97, 2142};
  std::list<int> stdlist{5, 3};
  s21list.merge(s21list2);
  stdlist.merge(stdlist2);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size() + 5, stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  ASSERT_EQ(s21list2.empty(), stdlist2.empty());
}

TEST(list_function_suit, splice) {
  s21::list<int> s21list{66, 44, 0, 97, 2142};
  s21::list<int> s21list2{5, 3};
  std::list<int> stdlist{66, 44, 0, 97, 2142};
  std::list<int> stdlist2{5, 3};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  s21list.splice(s21it, s21list2);
  stdlist.splice(stdit, stdlist2);
  ASSERT_EQ(s21list.size(), stdlist.size());
  ASSERT_EQ(s21list2.size(), stdlist2.size());
  s21it = s21list.begin();
  stdit = stdlist.begin();
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
  ASSERT_EQ(s21list2.empty(), stdlist2.empty());
}

TEST(list_function_suit, reverse) {
  s21::list<int> s21list{66, 44, 0, 97, 2142};
  std::list<int> stdlist{66, 44, 0, 97, 2142};
  s21list.reverse();
  stdlist.reverse();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_function_suit, unique_empty) {
  s21::list<int> s21list;
  ASSERT_ANY_THROW(s21list.unique());
}

TEST(list_function_suit, unique) {
  s21::list<int> s21list{1, 1, 1, 1, 222, 222, 2, 33, 3, 3};
  std::list<int> stdlist{1, 1, 1, 1, 222, 222, 2, 33, 3, 3};
  s21list.unique();
  stdlist.unique();
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_sort_suit, sort) {
  s21::list<int> s21list{66, 44, 0, 97, 2142};
  std::list<int> stdlist{66, 44, 0, 97, 2142};

  s21::list<int>::iterator s21it = s21list.begin();
  for (size_t i = 0; i < s21list.size(); i++) {
    std::cout << s21it.n_current->data << std::endl;
  }
  s21list.sort();
  stdlist.sort();

  s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();

  s21it = s21list.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    std::cout << s21it.n_current->data << std::endl;
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(list_iter_suit, iter_end) {
  s21::list<int> s21list{66, 44, 0, 97, 2142};
  std::list<int> stdlist{66, 44, 0, 97, 2142};
  s21::list<int>::iterator s21it = s21list.end();
  std::list<int>::iterator stdit = stdlist.end();
  stdit--;
  for (size_t i = 0; i < 2; i++) {
    s21it--;
    stdit--;
    ASSERT_EQ(*s21it, *stdit);
  }
}

TEST(list_iter_suit, iter) {
  s21::list<int> s21list{66, 44, 0, 97, 2142};
  s21::list<int>::iterator begin = s21list.begin();
  s21::list<int>::iterator begin1 = begin;
  ASSERT_TRUE(begin == begin1);
  ASSERT_FALSE(begin != begin1);
}

TEST(bonus_suit, emplace) {
  s21::list<int> s21list{66, 44, 0, 97, 2142};
  std::list<int> stdlist{66, 44, 0, 97, 2142};
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ++s21it;
  ++stdit;
  s21list.emplace(s21it, 5821);
  stdlist.emplace(stdit, 5821);
  ASSERT_EQ(s21list.size(), stdlist.size());
  s21it = s21list.begin();
  stdit = stdlist.begin();
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(bonus_suit, emplace_back) {
  s21::list<int> s21list{66, 44, 0, 97, 2142};
  std::list<int> stdlist{66, 44, 0, 97, 2142};
  s21list.emplace_back(5821);
  stdlist.emplace_back(5821);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

TEST(bonus_suit, emplace_front) {
  s21::list<int> s21list{66, 44, 0, 97, 2142};
  std::list<int> stdlist{66, 44, 0, 97, 2142};
  s21list.emplace_front(5821);
  stdlist.emplace_front(5821);
  s21::list<int>::iterator s21it = s21list.begin();
  std::list<int>::iterator stdit = stdlist.begin();
  ASSERT_EQ(s21list.size(), stdlist.size());
  for (size_t i = 0; i < s21list.size(); i++) {
    ASSERT_EQ(*s21it, *stdit);
    ++s21it;
    ++stdit;
  }
}

// Oleg
TEST(ALL, remains) {
  s21::list<int> example{3, 10, 2000};
  example = example;
}

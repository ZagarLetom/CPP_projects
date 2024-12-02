#include <gtest/gtest.h>

#include <array>

#include "s21_containersplus.h"

TEST(ALL_ARRAY, constructor_default) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  EXPECT_EQ(my_fake_array.size(), 5);
  EXPECT_EQ(my_fake_array.size(), original_array.size());
  EXPECT_NE(my_fake_array.data(), original_array.data());
  EXPECT_NE(my_fake_array.data(), nullptr);
  EXPECT_NE(original_array.data(), nullptr);
}

TEST(ALL_ARRAY, constructor_copy) {
  s21::array<int, 5> temp;
  s21::array<int, 5> my_fake_array(temp);
  std::array<int, 5> original_array;
  EXPECT_EQ(my_fake_array.size(), 5);
  EXPECT_EQ(my_fake_array.size(), original_array.size());
  EXPECT_NE(my_fake_array.data(), original_array.data());
  EXPECT_NE(original_array.data(), nullptr);
  EXPECT_NE(my_fake_array.data(), nullptr);
}

TEST(ALL_ARRAY, constructor_move) {
  s21::array<int, 5> temp;
  s21::array<int, 5> my_fake_array(std::move(temp));
  std::array<int, 5> original_array;
  EXPECT_EQ(my_fake_array.size(), original_array.size());
  EXPECT_NE(original_array.data(), nullptr);
  EXPECT_NE(my_fake_array.data(), nullptr);
  EXPECT_EQ(my_fake_array.size(), 5);
  EXPECT_EQ(temp.size(), 0);
  EXPECT_NE(my_fake_array.size(), temp.size());
  EXPECT_EQ(temp.data(), nullptr);
}

TEST(ALL_ARRAY, at) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  for (int i = 0; i < 5; i++) {
    my_fake_array.at(i) = i + 96;
    original_array.at(i) = i + 96;
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(my_fake_array.at(i), original_array.at(i));
  }
  EXPECT_ANY_THROW(my_fake_array.at(7));
  EXPECT_ANY_THROW(original_array.at(7));
}

TEST(ALL_ARRAY, overload_accessor) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  for (int i = 0; i < 5; i++) {
    my_fake_array[i] = i + 96;
    original_array[i] = i + 96;
  }
  for (int i = 0; i < 5; i++) {
    EXPECT_EQ(my_fake_array[i], original_array[i]);
  }
}

TEST(ALL_ARRAY, front) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  my_fake_array[0] = 97;
  EXPECT_NE(my_fake_array.front(), original_array.front());
  original_array[0] = 97;
  EXPECT_EQ(my_fake_array.front(), original_array.front());
}

TEST(ALL_ARRAY, back) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  my_fake_array[4] = 21;
  EXPECT_NE(my_fake_array.back(), original_array.back());
  original_array[4] = 21;
  EXPECT_EQ(my_fake_array.back(), original_array.back());
}

TEST(ALL_ARRAY, data) {
  s21::array<int, 0> my_fake_array;
  std::array<int, 0> original_array;
  EXPECT_EQ(my_fake_array.data(), nullptr);
  EXPECT_EQ(my_fake_array.data(), original_array.data());
  s21::array<int, 5> my_fake_array2;
  std::array<int, 5> original_array2;
  EXPECT_NE(my_fake_array2.data(), nullptr);
  EXPECT_NE(my_fake_array2.data(), original_array2.data());
}

TEST(ALL_ARRAY, begin) {
  s21::array<int, 0> my_fake_array;
  std::array<int, 0> original_array;
  EXPECT_EQ(my_fake_array.begin(), nullptr);
  EXPECT_EQ(my_fake_array.begin(), original_array.begin());
  s21::array<int, 5> my_fake_array2;
  std::array<int, 5> original_array2;
  EXPECT_NE(my_fake_array2.begin(), nullptr);
  EXPECT_NE(my_fake_array2.begin(), original_array2.begin());
}

TEST(ALL_ARRAY, end) {
  s21::array<int, 0> my_fake_array;
  std::array<int, 0> original_array;
  EXPECT_EQ(my_fake_array.end(), nullptr);
  EXPECT_EQ(my_fake_array.end(), original_array.end());
  s21::array<int, 5> my_fake_array2;
  std::array<int, 5> original_array2;
  EXPECT_NE(my_fake_array2.end(), nullptr);
  EXPECT_NE(my_fake_array2.end(), original_array2.end());
}

TEST(ALL_ARRAY, empty) {
  s21::array<int, 0> my_fake_array;
  std::array<int, 0> original_array;
  s21::array<int, 5> my_fake_array2;
  std::array<int, 5> original_array2;
  EXPECT_EQ(my_fake_array.empty(), true);
  EXPECT_EQ(original_array.empty(), true);
  EXPECT_NE(my_fake_array2.empty(), true);
  EXPECT_NE(original_array2.empty(), true);
}

TEST(ALL_ARRAY, size) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  EXPECT_EQ(my_fake_array.size(), original_array.size());
}

TEST(ALL_ARRAY, max_size) {
  s21::array<int, 5> m0;
  std::array<int, 5> o0;
  EXPECT_EQ(m0.max_size(), o0.max_size());
  s21::array<double, 5> m1;
  std::array<double, 5> o1;
  EXPECT_EQ(m1.max_size(), o1.max_size());
  s21::array<long long, 5> m2;
  std::array<long long, 5> o2;
  EXPECT_EQ(m2.max_size(), o2.max_size());
  s21::array<int, 5> m01;
  std::array<int, 5> o01;
  EXPECT_EQ(m01.max_size(), o01.max_size());
}

TEST(ALL_ARRAY, swap) {
  s21::array<int, 5> my_fake;
  std::array<int, 5> original;
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  my_fake[3] = 33;
  original[3] = 33;
  my_fake[4] = 0;
  original[4] = 0;
  my_fake_array[3] = 0;
  original_array[3] = 0;
  my_fake_array[4] = 44;
  original_array[4] = 44;
  my_fake.swap(my_fake_array);
  original.swap(original_array);
  EXPECT_EQ(my_fake[3], 0);
  EXPECT_EQ(my_fake[4], 44);
  EXPECT_EQ(original[3], 0);
  EXPECT_EQ(original[4], 44);
}

TEST(ALL_ARRAY, fill) {
  s21::array<int, 5> my_fake_array;
  std::array<int, 5> original_array;
  for (size_t i = 0; i < my_fake_array.size(); i++) {
    EXPECT_NE(my_fake_array[i], 41);
    EXPECT_NE(original_array[i], 77);
  }
  my_fake_array.fill(41);
  original_array.fill(77);
  for (size_t i = 0; i < my_fake_array.size(); i++) {
    EXPECT_EQ(my_fake_array[i], 41);
    EXPECT_EQ(original_array[i], 77);
  }
}

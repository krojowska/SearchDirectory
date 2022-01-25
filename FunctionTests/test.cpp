#include "pch.h"
#include "../Project3/èrÛd≥o.cpp"

/*TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}*/

TEST(ReturnValue, NumberOfLines) {
	ASSERT_EQ(2, noLines("C:/Users/My/Desktop/folder1/dok11.txt"));
}

TEST(ReturnValue, NumberOfWords) {
	ASSERT_EQ(2, noWords("C:/Users/My/Desktop/folder1/dok11.txt"));
}

TEST(ReturnValue, NumberOfLetters) {
	ASSERT_EQ(2, noLetters("C:/Users/My/Desktop/folder1/dok11.txt"));
}
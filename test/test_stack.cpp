#include "../include/stack.h"

#include <gtest.h>

TEST(Stack, empty ) {
	Stack<int> s;
	EXPECT_TRUE(s.empty());
	EXPECT_EQ(s.size(), 0);

}

TEST(Stack, push) {
	Stack<int> s;
	s.push(1);
	EXPECT_FALSE(s.empty());
	EXPECT_EQ(s.size(), 1);
	EXPECT_EQ(s.top(), 1);

	s.push(2);
	EXPECT_FALSE(s.empty());
	EXPECT_EQ(s.size(), 2);
	EXPECT_EQ(s.top(), 2);
}

TEST(Stack, pop) {
	Stack<int> s;
	s.push(1);
	s.push(2);
	EXPECT_EQ(s.top(), 2);

	s.pop();
	EXPECT_EQ(s.top(), 1);
	
	s.pop();
	EXPECT_EQ(s.size(), 0);
	EXPECT_TRUE(s.empty());
}

TEST(Stack, double) {
	Stack<double> s;
	s.push(1.1);
	s.push(2.2);

	EXPECT_EQ(s.top(), 2.2);

	s.pop();
	EXPECT_EQ(s.top(), 1.1);
}

TEST(Stack, clear) {
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.clear();
	EXPECT_EQ(s.size(), 0);
	EXPECT_TRUE(s.empty());
}

TEST(Stack, AfterEmpty) {
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.clear();
	s.push(1);
	s.push(2);
	EXPECT_EQ(s.top(), 2);
	s.pop();
	EXPECT_EQ(s.top(), 1);
}

TEST(Stack, AnyThrow) {
	Stack<int> s;
	EXPECT_ANY_THROW(s.top());
	EXPECT_ANY_THROW(s.pop());
}

TEST(Stack, StressTest) {
	Stack<int> s;
	const int N = 1000000;

	for (int i = 0; i < N; i++) {
		s.push(i);
		EXPECT_EQ(s.top(), i);
	}

	for (int i = N - 1; i >= 0; i--) {
		EXPECT_EQ(s.top(), i);
		s.pop();
	}

	EXPECT_TRUE(s.empty());
}
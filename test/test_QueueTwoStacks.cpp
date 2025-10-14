#include "../include/QueueTwoStacks.h"

#include <gtest.h>

TEST(QueueTwoStacks, empty) {
	QueueTwoStacks<int> s;
	EXPECT_EQ(s.size(), 0);
	EXPECT_TRUE(s.empty());
}

TEST(QueueTwoStacks, push) {
	QueueTwoStacks<int> s;
	s.push(1);
	EXPECT_FALSE(s.empty());
	EXPECT_EQ(s.size(), 1);
	EXPECT_EQ(s.back(), 1);

	s.push(2);
	EXPECT_FALSE(s.empty());
	EXPECT_EQ(s.size(), 2);
	EXPECT_EQ(s.back(), 2);

	s.push(3);
	EXPECT_FALSE(s.empty());
	EXPECT_EQ(s.size(), 3);
	EXPECT_EQ(s.back(), 3);

	s.push(4);
	EXPECT_FALSE(s.empty());
	EXPECT_EQ(s.size(), 4);
	EXPECT_EQ(s.back(), 4);
}

TEST(QueueTwoStacks, pop) {
	QueueTwoStacks<int> s;
	s.push(1);
	s.push(2);

	EXPECT_EQ(s.back(), 2);
	EXPECT_EQ(s.front(), 1);
	s.pop();
	EXPECT_EQ(s.back(), 2);
	EXPECT_EQ(s.front(), 2);

}

TEST(QueueTwoStacks, double) {
	QueueTwoStacks<double> s;
	s.push(1.1);
	s.push(2.2);

	EXPECT_EQ(s.back(), 2.2);
	EXPECT_EQ(s.front(), 1.1);

	s.pop();
	EXPECT_EQ(s.back(), 2.2);
	EXPECT_EQ(s.front(), 2.2);
}

TEST(QueueTwoStacks, clear) {
	QueueTwoStacks<int> s;
	s.push(1);
	s.push(2);
	s.clear();
	EXPECT_EQ(s.size(), 0);
	EXPECT_TRUE(s.empty());
}

TEST(QueueTwoStacks, AnyThrow) {
	QueueTwoStacks<int> s;
	EXPECT_ANY_THROW(s.back());
	EXPECT_ANY_THROW(s.front());
	EXPECT_ANY_THROW(s.pop());
}

TEST(QueueTwoStacks, AfterEmpty) {
	QueueTwoStacks<int> s;
	s.push(1);
	s.push(2);
	s.clear();
	s.push(1);
	s.push(2);
	EXPECT_EQ(s.back(), 2);
	EXPECT_EQ(s.front(), 1);
	s.pop();
	EXPECT_EQ(s.front(), 2);
	EXPECT_EQ(s.back(), 2);
}
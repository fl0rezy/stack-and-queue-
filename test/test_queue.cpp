#include "../include/queue.h"

#include <gtest.h>

TEST(Queue, empty) {
	Queue<int> s;
	EXPECT_EQ(s.size(), 0);
	EXPECT_TRUE(s.empty());
}

TEST(Queue, push) {
	Queue<int> s;
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

TEST(Queue, pop) {
	Queue<int> s;
	s.push(1);
	s.push(2);

	EXPECT_EQ(s.back(), 2);
	EXPECT_EQ(s.front(), 1);
	s.pop();
	EXPECT_EQ(s.back(), 2);
	EXPECT_EQ(s.front(), 2);

}

TEST(Queue, double) {
	Queue<double> s;
	s.push(1.1);
	s.push(2.2);

	EXPECT_EQ(s.back(), 2.2);
	EXPECT_EQ(s.front(),1.1);

	s.pop();
	EXPECT_EQ(s.back(), 2.2);
	EXPECT_EQ(s.front(), 2.2);
}

TEST(Queue, clear) {
	Queue<int> s;
	s.push(1);
	s.push(2);
	s.clear();
	EXPECT_EQ(s.size(), 0);
	EXPECT_TRUE(s.empty());
}

TEST(Queue, AnyThrow) {
	Queue<int> s;
	EXPECT_ANY_THROW(s.back());
	EXPECT_ANY_THROW(s.front());
	EXPECT_ANY_THROW(s.pop());
}

TEST(Queue, AfterEmpty) {
	Queue<int> s;
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

TEST(Queue, StressTest) {
	Queue<int> q;
	const int N = 1000000;

	for (int i = 0; i < N; i++) {
		q.push(i);
		EXPECT_EQ(q.back(), i);
		EXPECT_EQ(q.front(), 0);
	}
	EXPECT_EQ(q.back(), N - 1);
	EXPECT_EQ(q.front(), 0);
	for (int i = 0; i < N; i++) {
		EXPECT_EQ(q.front(), i);
		EXPECT_EQ(q.back(), N - 1);
		q.pop();
	}
	EXPECT_TRUE(q.empty());
}
#pragma once

#include "stack.h"

template<class T>

class QueueTwoStacks {
private:
	Stack<T> push_stack;
	Stack<T> pop_stack;

public:

	void push(const T& val) {
		push_stack.push(val);
	}

	bool empty() {
		return (push_stack.empty() && pop_stack.empty());
	}

	void pop() {
		if (empty()) {
			throw "Error";
		}

		if (pop_stack.empty()) {
			push_to_pop();
		}
		pop_stack.pop();
	}

	size_t size() {
		return push_stack.size() + pop_stack.size();
	}

	void clear() {
		push_stack.clear();
		pop_stack.clear();
	}

	T front() {
		if (empty()) {
			throw "Error";
		}
		if (pop_stack.empty()) {
			push_to_pop();
		}
		return pop_stack.top();
	}

	T back() {
		if (empty()) {
			throw "Error";
		}
		if (push_stack.empty()) {
			pop_to_push();
		}
		T val = push_stack.top();
		push_to_pop();
		return val;
		
	}

private:
	void push_to_pop() {
		while (!push_stack.empty()) {
			pop_stack.push(push_stack.top());
			push_stack.pop();
		}
	}
	void pop_to_push() {
		while (!pop_stack.empty()) {
			push_stack.push(pop_stack.top());
			pop_stack.pop();
		}
	}

};
#pragma once
#include "vector.h"

template <class T, class TContainer = Vector<T>>

class Stack {
private:
	TContainer data;
public:
	void push(const T& val) {
		data.push_back(val);
	}

	void pop() {
		if (empty()) {
			throw "Error";
		}
		data.pop_back();
	}

	T top() const {
		if (empty()) {
			throw "Error";
		}
		return data.back();
	}

	size_t size() const {
		return data.sizev();
	}

	void clear() {
		data.clear();
	}

	bool empty() const {
		return data.empty();
	}
};
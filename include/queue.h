#pragma once
#include "vector.h"

template <class T, class TContainer = Vector<T>>

class Queue {
private:
	TContainer data{2};
	size_t head=0;
	size_t tail=0;
	size_t count=0;
public:
	
	void push(const T& val){
		if (count == data.capacity()) {
			resize_queue(data.capacity() * 2);
		}
		data[tail] = val;
		tail = (tail + 1) % data.capacity();
		count++;
	}

	void pop() {
		if (empty()) {
			throw "Error";
		}
		head = (head + 1) % data.capacity();
		count--;
	}

	T front() const{
		if (empty()) {
			throw "Error";
		}
		return data[head];
	}

	T back() const{
		if (empty()) {
			throw "Error";
		}
		int index = (tail - 1 + data.capacity()) % data.capacity();
		return data[index];
	}

	size_t size() const{
		return count;
	}

	bool empty() const{
		return count==0;
	}

	void clear() {
		head = 0;
		tail = 0;
		count = 0;
	}

private:
	void resize_queue(size_t newcapacity) {
		Vector<T> newdata;
		newdata.resize(newcapacity);
		for (size_t i = 0; i < count; i++) {
			size_t index = (head + i) % data.capacity();
			newdata[i] = data[index];
		}
		data = newdata;
		head = 0;
		tail = count;
	}
};
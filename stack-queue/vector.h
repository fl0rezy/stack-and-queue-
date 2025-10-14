#pragma once
#include <iostream>

template <class T>

class Vector {
    T* data = nullptr;
    size_t size = 0;
    size_t memory;
public:

    Vector() : data(nullptr), size(0), memory(0) {}

    Vector(int n) : size(n), memory(n) {
        data = new T[n];
        for (int i = 0; i < n; i++) {
            data[i] = T();
        }
    }

    Vector(int n, T value) {
        size = n;
        memory = n;
        if (n == 0) {
            throw "Error: incorrect size";
        }
        data = new T[n];
        for (int i = 0; i < n; i++) {
            data[i] = value;
        }
    }

    Vector(const T* arr, size_t arr_size) {
        if (arr != nullptr && arr_size > 0) {
            size = memory = arr_size;
            data = new T[memory];
            for (int i = 0; i < size; ++i) {
                data[i] = arr[i];
            }
        }
    }

    Vector(const Vector& v) {
        size = v.size;
        memory = v.memory;
        if (v.size == 0) {
            throw "Error: incorrect size";
        }
        data = new T[v.size];
        for (int i = 0; i < v.size; i++) {
            data[i] = v.data[i];
        }
    }

    Vector(T* start, T* end) {
        size = memory = end - start;
        if (size <= 0) {
            throw "Error: incorrect size";
        }
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = start[i];
        }
    }

    ~Vector() {
        delete[] data;
    }

    Vector& operator=(const Vector& source) {
        if (this == &source) {
            return *this;
        }
        delete[] data;
        size = source.size;
        memory = source.memory;
        data = new T[memory];
        for (int i = 0; i < size; ++i) {
            data[i] = source.data[i];
        }
        return *this;
    }

    T& operator[](size_t index) {
        if (index < size) {
            return data[index];
        }
        throw "Error: incorrect index";
    }

    const T& operator[](size_t index) const {
        if (index < size) {
            return data[index];
        }
        throw "Error: incorrect index";
    }

    void  print() const {
        if (size == 0) {
            std::cout << "Size=0" << std::endl;
            return;
        }
        for (size_t i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    size_t  sizev() const{
        return size;
    }

    bool  empty() const{
        return size == 0;
    }

    void  clear() {
        size = 0;
    }
private:
    void  reserve(size_t newmemory) {
        if (newmemory <= memory) {
            return;
        }
        T* new_data = new T[newmemory];
        for (int i = 0; i < size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        memory = newmemory;
    }
public:
    void resize(size_t newsize, T value = T()) {
        if (newsize == size) {
            std::cout << "Size haven't changed" << std::endl;
            return;
        }
        if (newsize < size) {
            size = newsize;
        }
        else {
            if (newsize >= memory) {
                size_t new_memory = (memory == 0) ? newsize : std::max(newsize, memory * 2);
                reserve(new_memory);
            }
            for (size_t i = size; i < newsize; i++) {
                data[i] = value;
            }
            size = newsize;
        }
    }

    size_t  insert(size_t pos, T value) {
        if (pos > size) {
            throw "Out of range";
        }
        if (size + 1 > memory) {
            reserve(memory * 2);
        }
        for (size_t i = size; i > pos; i--) {
            data[i] = data[i - 1];
        }
        data[pos] = value;
        size += 1;

        return pos;
    }

    void push_back(T value) {
        if (size + 1 > memory) {
            size_t new_memory = (memory == 0) ? 1 : memory * 2;
            reserve(new_memory);
        }
        data[size] = value;
        size++;
    }

    void  pop_back() {
        if (size > 0) {
            size -= 1;
        }
    }

    void  swap(Vector& other) {
        T* tmp_data = data;
        data = other.data;
        other.data = tmp_data;
        size_t tmp_size = size;
        size = other.size;
        other.size = tmp_size;
        size_t tmp_memory = memory;
        memory = other.memory;
        other.memory = tmp_memory;
    }

    size_t  erase(size_t pos) {
        if (pos >= size) {
            throw "Out of range";
        }
        for (size_t i = pos; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size -= 1;
        return pos;
    }

    size_t  erase(size_t first, size_t last) {
        if (first > last || last > size) {
            throw "Out of range";
        }
        if (first == last) {
            return first;
        }
        size_t count = last - first;
        for (size_t i = last; i < size; i++) {
            data[i - count] = data[i];
        }
        size -= count;
        return first;
    }

    size_t  insert(size_t pos, const T* first, const T* last) {
        if (pos > size) {
            throw "Out of range";
        }
        if (first >= last) {
            return pos;
        }
        size_t count = last - first;
        if (size + count > memory) {
            reserve(memory * 2);
        }
        for (size_t i = size; i > pos; i--) {
            data[i + count - 1] = data[i - 1];
        }
        for (size_t i = 0; i < count; i++) {
            data[pos + i] = first[i];
        }
        size += count;
        return pos;
    }

    size_t  capacity() const {
        return memory;
    }

    size_t  acceptable_size() {
        return memory - size;
    }

    T* datav() {
        return data;
    }

    const T* datav() const {
        return data;
    }

    T& front() {
        if (size == 0) {
            throw "Vector is empty!";
        }
        return data[0];
    }

    const T& front() const {
        if (size == 0) {
            throw "Vector is empty!";
        }
        return data[0];
    }

    T& back() {
        if (size == 0) {
            throw "Vector is empty!";
        }
        return data[size - 1];
    }

    const T& back() const {
        if (size == 0) {
            throw "Vector is empty!";
        }
        return data[size - 1];
    }

    T& at(size_t index) {
        if (index < size) {
            return data[index];
        }
        throw "Error: incorrect index";
    }

    T  at(size_t index) const {
        if (index < size) {
            return data[index];
        }
        throw "Error: incorrect index";
    }

    void  assign(size_t count, T value) {
        delete[] data;
        memory = size = count;
        data = new T[memory];
        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    }

    void  assign(const T* first, const T* last) {
        size_t count = last - first;
        delete[] data;
        memory = size = count;
        data = new T[memory];
        for (size_t i = 0; i < size; ++i) {
            data[i] = first[i];
        }
    }

    bool  operator==(const Vector& other) const {
        if (size != other.size) return false;
        for (size_t i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    bool  operator!=(const Vector& other) const {
        return !(*this == other);
    }

    bool  operator<(const Vector& other) const {
        size_t min_size = std::min(size, other.size);
        for (size_t i = 0; i < min_size; i++) {
            if (data[i] < other.data[i]) return true;
            if (data[i] > other.data[i]) return false;
        }
        return size < other.size;
    }

    bool  operator<=(const Vector& other) const {
        return !(other < *this);
    }

    bool  operator>(const Vector& other) const {
        return other < *this;
    }

    bool  operator>=(const Vector& other) const {
        return !(*this < other);
    }
};
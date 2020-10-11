#pragma once

#include <cstdlib>

// Реализуйте шаблон SimpleVector
template <typename T>
class SimpleVector {
public:
    SimpleVector() {
        data = nullptr;
        end_ = data;
        capacity = 0;
    }
    explicit SimpleVector(size_t size) {
        data = new T[size];
        end_ = data + size;
        capacity = size;
    }
    ~SimpleVector() {
        delete[] data;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    T* begin() { return data; }
    T* end() { return end_;}

    const T* begin() const { return data; }
    const T* end() const { return end_;}

    size_t Size() const {
        return end_ - data;
    }
    size_t Capacity() const {
        return capacity;
    }
    void PushBack(const T& value) {
        if (Capacity() == Size()) {
            if (capacity == 0) {
              capacity = 1;
            } else {
              capacity = 2*Capacity();
            }
            T* new_segment = new T[capacity];
            CopyData(data, new_segment);
            delete[] data;
            data = new_segment;
        }
        data[index_of_last_element] = value; 
        index_of_last_element ++;
        end_ = data + index_of_last_element;  
    }

private:
    T* data;
    T* end_;
    size_t capacity = 0;
    size_t index_of_last_element = 0;

    void CopyData(T* &from, T* &to) {
      T* from_ = from;
      T* to_ = to;
        while (from_ != end_) {
            *to_ = *from_;
            from_++;
            to_++;
        }
    }
};

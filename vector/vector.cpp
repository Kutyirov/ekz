#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t() {
  size_ = 0;
  capacity_ = 0;
  elements_ = nullptr;
}

vector_t::vector_t(vector_t const& other) {
  size_ = other.size_;
  capacity_ = other.capacity_;
  elements_ = new int[capacity_];
  for (int i = 0; i < size_; i++) elements_[i] = other.elements_[i];
}

vector_t& vector_t::operator=(vector_t const& other) {
  size_ = other.size_;
  capacity_ = other.capacity_;
  delete[] elements_;
  elements_ = new int[capacity_];
  for (int i = 0; i < size_; i++) elements_[i] = other.elements_[i];
  return *this;
}

bool vector_t::operator==(vector_t const& other) const {
  bool flag = false;
  if (size_ == other.size_) {
    flag = true;
    for (int i = 0; i < size_; i++)
      if (elements_[i] != other.elements_[i]) flag = false;
  }
  return flag;
}

vector_t::~vector_t() {
  size_ = 0;
  capacity_ = 0;
  delete[] elements_;
}

std::size_t vector_t::size() const { return size_; }

std::size_t vector_t::capacity() const { return capacity_; }

void vector_t::push_back(int value) {
  if (capacity_ == 0) {
    capacity_ = 1;
    size_ = 1;
    elements_ = new int[capacity_];
    elements_[0] = value;
  } else {
    if (size_ == capacity_) capacity_ *= 2;
    int* elements_2 = new int[capacity_];
    for (int i = 0; i < size_; i++) elements_2[i] = elements_[i];
    elements_2[size_] = value;
    size_++;
    delete[] elements_;
    elements_ = elements_2;
  }
}

void vector_t::pop_back() {
  if (size_ == 0) return;
  size_ = size_ - 1;
  if (size_ * 4 <= capacity_) capacity_ = capacity_ / 2;
  int* elements_2 = new int[capacity_];
  for (int i = 0; i < size_; i++) elements_2[i] = elements_[i];
  delete[] elements_;
  elements_ = elements_2;
}

int& vector_t::operator[](std::size_t index) { return elements_[index]; }

int vector_t::operator[](std::size_t index) const { return elements_[index]; }

bool operator!=(vector_t const& lhs, vector_t const& rhs) {
  return !(lhs == rhs);
}

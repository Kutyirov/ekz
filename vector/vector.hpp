#include <iostream>

class vector_t {
 private:
  int* elements_;
  std::size_t size_;
  std::size_t capacity_;

 public:
  vector_t();
  vector_t(vector_t const& other);
  vector_t& operator=(vector_t const& other);
  ~vector_t();

  std::size_t size() const;
  std::size_t capacity() const;

  void push_back(int value);
  void pop_back();

  int& operator[](std::size_t index);
  int operator[](std::size_t index) const;

  bool operator==(vector_t const& other) const;
};

bool operator!=(vector_t const& lhs, vector_t const& rhs);

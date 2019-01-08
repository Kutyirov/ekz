#ifndef INCLUDE_SHARED_PTR_HPP_
#define INCLUDE_SHARED_PTR_HPP_

#endif  // INCLUDE_SHARED_PTR_HPP_

#include <iostream>
//#include <atomic>
#include <utility>

template <typename T>
class SharedPtr {
  struct control_block {
    unsigned int count;
  };
  control_block block;
  T* ptr;

 public:
  SharedPtr() {
    ptr = nullptr;
    block.count = 1;
  }

  explicit SharedPtr(T* p) {
    ptr = p;
    block.count = 1;
  }

  SharedPtr(const SharedPtr& r) {
    ptr = r.ptr;
    block.count = r.block.count;
    block.count++;
  }

  SharedPtr(const SharedPtr&& r) {  //перенос
    swap(r);
  }

  bool operator==(const SharedPtr& r) {
    return (ptr == r.ptr && block.count == r.block.count);
  }
  SharedPtr& operator=(const SharedPtr& r) {
    if (*this == r) {
      return *this;
    }
    SharedPtr<T>{r}.swap(*this);
    return *this;
  }

  ~SharedPtr() {
    if (block.count - 1 == 0) {
      ptr = nullptr;
      block.count = 0;
    } else {
      block.count = block.count - 1;
    }
  }

  void reset() {
    ptr = nullptr;
    block.count = 0;
  }

  void reset(T* something) {
    reset();
    ptr = something;
  }

  void swap(SharedPtr& another) {
    std::swap(another.ptr, ptr);
    std::swap(another.block.count, block.count);
  }

  T* get() { return ptr; }

  T& operator*() const {
    if (*this) {
      return *(this->data);
    }

    return std::runtime_error("pointer was nullptr");
  }

  T* operator->() const { return ptr; }

  size_t use_count() const { return block.count; }
};

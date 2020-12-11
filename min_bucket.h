#pragma once
#include <algorithm>
#include <cstddef> // for size_t
#include <exception>

// A min_bucket of size n stores the smallest (at most) n
// objects ever inserted within.

template <typename T>
class min_bucket {
public:
  min_bucket(size_t);
  ~min_bucket();
  void insert(const T&);
  T operator[](size_t);
  // make copy constructor and copy assignment unavailable
  min_bucket(const min_bucket&) = delete;
  min_bucket& operator=(const min_bucket&) = delete;
private:
  const size_t size; // must be initialized
  int count; // number of objects stored
  T* items = nullptr;
};

template <typename T>
min_bucket<T>::min_bucket(size_t n): size(n), count(0)
{
  items = new T[n+1];
  if (items == nullptr) throw std::exception();
}

template <typename T>
min_bucket<T>::~min_bucket()
{
  delete [] items;
}

template <typename T>
void min_bucket<T>::insert(const T& x)
{
  if (count < size) {
    items[count] = x;
  }
  else { // full
    items[size] = x; // place x at the end
  }
  int i = count-1;
  while (i >= 0  && items[i+1] < items[i]) {
    std::swap(items[i], items[i+1]);
    i--;
  }
  if (count < size) count++;
}

template <typename T>
T min_bucket<T>::operator[](size_t n)
{
  if (n >= size) throw std::exception();
  return items[n];
}

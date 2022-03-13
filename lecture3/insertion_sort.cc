#include <iostream>
#include <optional>
#include <vector>

#include "utils.h"

// TODO: extend the sort to generic types and compare
// The following function sort vector in ascending order by default
template <typename T, typename Compare = std::greater<T>>
void InsertionSortOrg(std::vector<T>* v) {
  for (int i = 1; i < v->size(); ++i) {
    int k = i;
    while (k > 0 && Compare()((*v)[k-1], (*v)[k])) {
      std::swap((*v)[k-1], (*v)[k]);
      --k;
    }
  }
}

// Insertion sort using iterators instead of index
template <typename T, typename Compare = std::greater<T>>
void InsertionSort(std::vector<T>* v) {
  for (typename std::vector<T>::iterator itr = std::next(v->begin()); itr != v->end(); ++itr) {
    typename std::vector<T>::iterator key = itr;
    typename std::vector<T>::iterator key_prev = std::prev(key);
    while (key != v->begin() && Compare()(*key_prev, *key)) {
      // Note that iter_swap swaps the element value not really the iterator
      std::iter_swap(key, key_prev);
      --key;
      key_prev = std::prev(key);
    }
  }
}

int main() {
  std::vector<int> in = {5, 2, 4, 6, 1, 3};
  std::cout << in << std::endl;
  InsertionSortOrg(&in);
  std::cout << in << std::endl;
  InsertionSort<int, std::less<int>>(&in);
  std::cout << in << std::endl;
  return 0;
}

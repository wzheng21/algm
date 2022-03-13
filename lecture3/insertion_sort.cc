#include <iostream>
#include <optional>
#include <vector>

#include "utils.h"

// TODO: extend the sort to generic types and compare
// The following function sort vector in ascending order by default
template <typename T, typename Compare = std::greater<T>>
void InsertionSort(std::vector<T>* v) {
  for (int i = 1; i < v->size(); ++i) {
    int k = i;
    while (k > 0 && Compare()((*v)[k-1], (*v)[k])) {
      std::swap((*v)[k-1], (*v)[k]);
      --k;
    }
  }
}

int main() {
  std::vector<int> in = {5, 2, 4, 6, 1, 3};
  std::cout << in << std::endl;
  InsertionSort(&in);
  std::cout << in << std::endl;
  InsertionSort<int, std::less<int>>(&in);
  std::cout << in << std::endl;
  return 0;
}

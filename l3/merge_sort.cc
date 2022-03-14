#include "utils.h"

template <typename Container, typename Compare>
void Merge(Compare comp, const Container& c1, const Container& c2, Container* v) {
  Container r;
  typename Container::const_iterator b1 = c1.cbegin();
  typename Container::const_iterator b2 = c2.cbegin();
  typename Container::const_iterator e1 = c1.cend();
  typename Container::const_iterator e2 = c2.cend();
  while (!(b1 == e1 && b2 == e2)) {
    if (b1 == e1) {
      r.push_back(*b2++);
    } else if (b2 == e2) {
      r.push_back(*b1++);
    } else if (comp(*b1, *b2)) {
      r.push_back(*b1++);
    } else if (!comp(*b1, *b2)) {
      r.push_back(*b2++);
    }
  }
  *v = std::move(r);
}

// This implementation doesn't work with containers that doesn't have size() API
template <typename Container, typename Compare>
void MergeSort(Compare comp, Container* v) {
  if (v->size() <= 1) return;
  if (v->size() == 2 && !comp(v->front(), v->back())) {
    std::swap(v->front(), v->back());
    return;
  }
  typename Container::iterator mid = v->begin();
  std::advance(mid, v->size() / 2);
  Container c1(v->begin(), mid);
  Container c2(mid, v->end());
  MergeSort(comp, &c1);
  MergeSort(comp, &c2);
  Merge(comp, c1, c2, v);
}

int main() {
  std::vector<int> in = {5, 2, 4, 6, 1, 3};
  std::cout << in << std::endl;
  MergeSort(std::less<int>(), &in);
  std::cout << in << std::endl;
  std::list<int> in2 = {5, 2, 4, 6, 1, 3};
  MergeSort(std::greater<int>(), &in2);
  std::cout << in2 << std::endl;
  return 0;
}

#include "utils.h"

template <typename Container, typename Compare, typename IterType = typename Container::iterator>
void Merge(Compare comp, IterType b1, IterType e1, IterType b2, IterType e2, Container* v) {
  Container r;
  while (b1 != e1 && b2 != e2) {
    if (comp(*b1, *b2)) {
      r.push_back(*b1);
      ++b1;
    } else {
      r.push_back(*b2);
      ++b2;
    }
  }
}

template <typename Container, typename Compare>
void MergeSort(Compare comp, Container* v) {
  if (v->size() <= 1) return;
  if (v->size() == 2 && !comp(v->front(), v->back())) {
    std::swap(v->front(), v->back());
    return;
  }
  typename Container::iterator mid = std::advance(v->begin(), v->size() / 2);
  Container c1(v->begin(), mid);
  Container c2(mid, v->end());
  MergeSort(comp, &c1);
  MergeSort(comp, &c2);
  Merge(comp, v->begin(), mid, mid, v->end(), v);
}

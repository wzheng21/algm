#pragma once

#include "utils.h"

#include <iterator>

template <typename T>
std::ostream& operator<<(std::ostream& in, const std::vector<T>& c) {
  if (c.empty()) return in;
  in << c.front();
  for (typename std::vector<T>::const_iterator citr = std::next(c.cbegin()); citr < c.cend(); ++citr) {
    in  << ", " << *citr;
  }
  return in;
}

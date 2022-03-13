#pragma once

#include <iostream>
#include <list>
#include <forward_list>
#include <optional>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& in, const std::vector<T>& c);
template <typename T>
std::ostream& operator<<(std::ostream& in, const std::list<T>& c);

#include "utils-impl.h"

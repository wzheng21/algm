#pragma once

#include <iostream>
#include <list>

template <typename T>
std::ostream& operator<<(std::ostream& in, const std::vector<T>& c);
template <typename T>
std::ostream& operator<<(std::ostream& in, const std::list<T>& c);

#include "utils-impl.h"

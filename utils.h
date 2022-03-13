#pragma once

#include <iostream>

template <typename T>
std::ostream& operator<<(std::ostream& in, const std::vector<T>& c);

#include "utils-impl.h"

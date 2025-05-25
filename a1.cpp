#include <iostream>

static long long symbolComparisons = 0;

bool strLess(const std::string &a, const std::string &b) {
  ++symbolComparisons;
  return a < b;
}
#include "test.hpp"

#include <chrono>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <random>

namespace with_attributes {
constexpr double pow(double x, long long n) noexcept {
  if (n > 0) [[likely]]
    return x * pow(x, n - 1);
  else [[unlikely]]
    return 1;
}
constexpr long long fact(long long n) noexcept {
  if (n > 1) [[likely]]
    return n * fact(n - 1);
  else [[unlikely]]
    return 1;
}
constexpr double cos(double x) noexcept {
  constexpr long long precision{16LL};
  double y{};
  for (auto n{0LL}; n < precision; n += 2LL) {
    [[likely]] y += pow(x, n) / (n & 2LL ? -fact(n) : fact(n));
  }
  return y;
}
}; // namespace with_attributes

namespace no_attributes {
constexpr double pow(double x, long long n) noexcept {
  if (n > 0)
    return x * pow(x, n - 1);
  else
    return 1;
}
constexpr long long fact(long long n) noexcept {
  if (n > 1)
    return n * fact(n - 1);
  else
    return 1;
}
constexpr double cos(double x) noexcept {
  constexpr long long precision{16LL};
  double y{};
  for (auto n{0LL}; n < precision; n += 2LL) {
    y += pow(x, n) / (n & 2LL ? -fact(n) : fact(n));
  }
  return y;
}
}; // namespace no_attributes

double gen_random() noexcept {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_real_distribution<double> dis(-1.0, 1.0);
  return dis(gen);
}

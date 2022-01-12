namespace with_attributes {
constexpr double pow(double x, long long n) noexcept;
constexpr long long fact(long long n) noexcept;
constexpr double cos(double x) noexcept;
}; // namespace with_attributes

namespace no_attributes {
constexpr double pow(double x, long long n) noexcept;
constexpr long long fact(long long n) noexcept;
constexpr double cos(double x) noexcept;
}; // namespace no_attributes

double gen_random() noexcept;

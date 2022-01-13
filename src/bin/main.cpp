#include <test.hpp>

#include <chrono>
#include <iomanip>
#include <iostream>

volatile double sink {};

int main()
{
    for (const auto x : { 0.125, 0.25, 0.5, 1. / (2 << 25) }) {
        std::cout
            << std::setprecision(53)
            << "x = " << x << '\n'
            << std::cos(x) << '\n'
            << with_attributes::cos(x) << '\n'
            << (std::cos(x) == with_attributes::cos(x) ? "equal" : "differ") << '\n';
    }

    auto benchmark = [](auto fun, auto rem) {
        const auto start = std::chrono::high_resolution_clock::now();
        for (auto size { 1ULL }; size != 10'000'000ULL; ++size) {
            sink = fun(gen_random());
        }
        const std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << "Time: " << std::fixed << std::setprecision(6) << diff.count()
                  << " sec " << rem << std::endl;
    };

    benchmark(with_attributes::cos, "(with attributes:)");
    benchmark(no_attributes::cos, "(without attributes)");
    benchmark(cos, "(std::cos)");
}
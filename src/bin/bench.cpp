#include <test.hpp>

#include <benchmark/benchmark.h>

static void BM_with(benchmark::State& state)
{
    double x { 0.1 };
    for (auto _ : state) {
        benchmark::DoNotOptimize(with_attributes::cos(x));
    }
}
BENCHMARK(BM_with);

static void BM_without(benchmark::State& state)
{
    double x { 0.1 };
    for (auto _ : state) {
        benchmark::DoNotOptimize(no_attributes::cos(x));
    }
}
BENCHMARK(BM_without);

static void BM_std(benchmark::State& state)
{
    double x { 0.1 };
    for (auto _ : state) {
        benchmark::DoNotOptimize(std::cos(x));
    }
}
BENCHMARK(BM_std);

static void BM_rstd1(benchmark::State& state)
{
    double x = gen_random();
    for (auto _ : state) {
        benchmark::DoNotOptimize(std::cos(x));
    }
}
BENCHMARK(BM_rstd1);

BENCHMARK_MAIN();
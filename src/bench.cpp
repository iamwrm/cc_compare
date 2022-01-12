#include "test.hpp"

#include <benchmark/benchmark.h>

static void BM_with(benchmark::State& state)
{
    for (auto _ : state) {
        benchmark::DoNotOptimize(with_attributes::cos(0.1));
        benchmark::DoNotOptimize(with_attributes::cos(0.1));
    }
}
BENCHMARK(BM_with);

static void BM_without(benchmark::State& state)
{
    for (auto _ : state) {
        benchmark::DoNotOptimize(no_attributes::cos(0.1));
    }
}
BENCHMARK(BM_without);

static void BM_std(benchmark::State& state)
{
    for (auto _ : state) {
        benchmark::DoNotOptimize(std::cos(0.1));
    }
}
BENCHMARK(BM_std);

static void BM_rstd1(benchmark::State& state)
{
    for (auto _ : state) {
        benchmark::DoNotOptimize(gen_random());
        benchmark::DoNotOptimize(gen_random());
    }
}
BENCHMARK(BM_rstd1);

static void BM_rstd2(benchmark::State& state)
{
    for (auto _ : state) {
        auto input = gen_random();
        benchmark::DoNotOptimize(std::cos(input));
    }
}
BENCHMARK(BM_rstd2);

BENCHMARK_MAIN();
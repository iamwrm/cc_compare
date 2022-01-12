#include <benchmark/benchmark.h>

static void BM_B1(benchmark::State& state)                     
{                                                                
    for (auto _ : state) {                                       
        // benchmark::DoNotOptimize(expesssion_template::op(1, 2)); 
    }                                                            
}                                                                
BENCHMARK(BM_B1);


BENCHMARK_MAIN();
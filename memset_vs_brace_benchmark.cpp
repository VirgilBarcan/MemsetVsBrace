//
// Created by virgil on 08.02.2018.
//

#include <benchmark/benchmark.h>
#include <cstring>

struct S
{
    uint8_t a1;
    uint16_t a2;
    uint32_t a3;
    int64_t a4;
    float x;
    float y;
    float z;
    uint64_t val;
};

void BM_memset(benchmark::State &state) {
    for (auto _ : state)
    {
        state.PauseTiming();

        // build struct
        S s1;

        state.ResumeTiming();

        memset(&s1, 0, sizeof(s1));
    }
}

void BM_braces(benchmark::State &state) {
    for (auto _ : state)
    {
        state.PauseTiming();

        // build struct
        S s1;

        state.ResumeTiming();

        s1 = {};
    }
}

BENCHMARK(BM_memset)->RangeMultiplier(2)->Range(8, 8<<10);
BENCHMARK(BM_braces)->RangeMultiplier(2)->Range(8, 8<<10);

BENCHMARK_MAIN();

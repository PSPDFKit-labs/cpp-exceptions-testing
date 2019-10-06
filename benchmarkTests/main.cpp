#include "FunctionsToTest.hpp"

#include <iostream>
#include <stdexcept>
#include <benchmark/benchmark.h>

#define BLACKHOLE(expr) do { (void)(expr); } while (0)

namespace {

void BM_exitWithStdException(benchmark::State& state) {
    for (auto _ : state) {
        try {
            exitWithStdException();
        } catch (const std::runtime_error &ex) {
            // caught!  carry on next iteration.
            BLACKHOLE(ex);
        }
    }
}
void BM_exitWithIntException(benchmark::State& state) {
    for (auto _ : state) {
        try {
            exitWithIntException();
        } catch (int ex) {
            // caught!  carry on next iteration.
            BLACKHOLE(ex);
        }
    }
}
void BM_exitWithReturn(benchmark::State& state) {
    for (auto _ : state) {
        exitWithReturn();
    }
}
void BM_exitWithErrorCode(benchmark::State& state) {
    for (auto _ : state) {
        auto err = exitWithErrorCode();
        if (err < 0) {
            // handle_error()
            BLACKHOLE(err);
        }
    }
}

}


BENCHMARK(BM_exitWithStdException);
BENCHMARK(BM_exitWithIntException);
BENCHMARK(BM_exitWithReturn);
BENCHMARK(BM_exitWithErrorCode);

BENCHMARK_MAIN();


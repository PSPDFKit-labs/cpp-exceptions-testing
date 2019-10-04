#include <iostream>
#include <exception>

#include <benchmark/benchmark.h>

namespace {

void exitWithIntException() {
    for (int i{0}; i < 5; ++i) {
        throw -2;
    }
}

void exitWithStdException() {
    for (int i{0}; i < 5; ++i) {
        throw std::runtime_error("Exception!");
    }
}

void exitWithReturn() {
    for (int i{0}; i < 5; ++i) {
        return;
    }
}

void exitWithBreak() {
    for (int i{0}; i < 5; ++i) {
        break;
    }
}

int exitWithErrorCode() {
    for (int i{0}; i < 5; ++i) {
        return -1;
    }
    return 0;
}



void BM_exitWithStdException(benchmark::State& state) {
    for (auto _ : state) {
        try {
            exitWithStdException();
        } catch (const std::runtime_error &ex) {
            // caught!  carry on next iteration.
        }
    }
}
void BM_exitWithIntException(benchmark::State& state) {
    for (auto _ : state) {
        try {
            exitWithIntException();
        } catch (int ex) {
            // caught!  carry on next iteration.
        }
    }
}

void BM_exitWithReturn(benchmark::State& state) {
    for (auto _ : state) {
        exitWithReturn();
    }
}

void BM_exitWithBreak(benchmark::State& state) {
    for (auto _ : state) {
        exitWithBreak();
    }
}

void BM_exitWithErrorCode(benchmark::State& state) {
    for (auto _ : state) {
        auto err = exitWithErrorCode();
        if (err < 0) {
            // handle_error()
        }
    }
}

}


BENCHMARK(BM_exitWithStdException);
BENCHMARK(BM_exitWithIntException);
BENCHMARK(BM_exitWithReturn);
BENCHMARK(BM_exitWithBreak);
BENCHMARK(BM_exitWithErrorCode);

BENCHMARK_MAIN();


#include <iostream>
#include <exception>

#include <benchmark/benchmark.h>

static const int TEST_ITERATIONS = 1000;

void exitWithException() {
    for (int i{0}; i < 10; ++i) {
        throw std::runtime_error("Exception!");
    }
}

void exitWithReturn() {
    for (int i{0}; i < 10; ++i) {
        return;
    }
}

void exitWithBreak() {
    for (int i{0}; i < 10; ++i) {
        break;
    }
}


auto IntToStringConversionTest(int count)
{
    std::vector<int> inputNumbers(count);
    std::vector<std::string> outNumbers;

    iota(begin(inputNumbers), end(inputNumbers), 0);
    for (auto &num : inputNumbers)
        outNumbers.push_back(to_string(num));

    return outNumbers;
}

void exitWithException(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                IntToStringConversionTest(state.range_x())
        );
    }
}
BENCHMARK(IntToString)->Arg(TEST_ITERATIONS);

void DoubleToString(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(
                DoubleToStringConversionTest(state.range_x())
        );
    }
}
BENCHMARK(DoubleToString)->Arg(TEST_ITERATIONS);

BENCHMARK_MAIN()




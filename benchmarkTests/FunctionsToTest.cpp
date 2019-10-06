#include "FunctionsToTest.hpp"
#include <stdexcept>
#include <functional>


namespace {

const int randomRange = 2;
const int errorInt = 1;
int getRandom() { return random() % randomRange; }


template<typename T>
T testFunction(const std::function<T()>& fn) {
    auto num = getRandom();
    for (int i{0}; i < 5; ++i) {
        if (num == errorInt) {
            return fn();
        }
    }
}

}



void exitWithIntException() {
    testFunction<void>([]() -> void {
        throw -2;
    });
}

void exitWithStdException() {
    testFunction<void>([]() -> void {
        throw std::runtime_error("Exception!");
    });
}

void exitWithReturn() {
    testFunction<void>([]() -> void {
        return;
    });
}

int exitWithErrorCode() {
    testFunction<int>([]() -> int {
        return -1;
    });

    return 0;
}

//
// Created by Amit on 2019-10-04.
//

#include "FunctionsToTest.hpp"
#include <stdexcept>

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

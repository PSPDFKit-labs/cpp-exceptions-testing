//#include <iostream>
//#include <exception>
//
//
//namespace {
//
//void exitWithStdException() {
//    for (int i{0}; i < 5; ++i) {
//        throw std::runtime_error("Exception!");
//    }
//}
//
//}
//
//int main(int argc, char** argv) {
//    try {
//        exitWithStdException();
//    } catch (const std::runtime_error& ex) {
//        std::cout << ex.what() << std::endl;
//    }
//}
//


#include <stdio.h>
#include <time.h>

#define BIG 1000000

int f( int n ) {
    int r = 0, i = 0;
    for ( i = 0; i < 1000; i++ ) {
        r += i;
        if ( n == BIG - 1 ) {
            throw -1;
        }
    }
    return r;
}

int main() {
    clock_t start = clock();
    int i = 0, z = 0;
    for ( i = 0; i < BIG; i++ ) {
        try {
            z += f(i);
        }
        catch( ... ) {
            break;
        }

    }
    double t  = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf( "%f\n", t );
    printf( "%d\n", z );
}
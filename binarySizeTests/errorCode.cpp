//#include <iostream>
//
//namespace {
//
//int exitWithErrorCode() {
//    for (int i{0}; i < 5; ++i) {
//        return -2;
//    }
//    return 0;
//}
//
//}
//
//int main(int argc, char** argv) {
//    auto err = exitWithErrorCode();
//    if (err < 0) {
//        std::cout << "Error happened." << std::endl;
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
            return -1;
        }
    }
    return r;
}

int main() {
    clock_t start = clock();
    int i = 0, z = 0;
    for ( i = 0; i < BIG; i++ ) {
        if ( (z = f(i)) == -1 ) {
            break;
        }
    }
    double t  = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf( "%f\n", t );
    printf( "%d\n", z );
}
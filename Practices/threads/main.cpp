//
//  main.cpp
//  INTROTHREADS
//
//  Created by Eralp  Kızıloğlu on 3.01.2023.
//

/*
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef long long int  ull;

void findEven(ull start, ull end, ull* EvenSum) {
    for (ull i = start; i <= end; ++i){
        if (!(i & 1)){
            *(EvenSum) += i;
        }
    }
}

void findOdd(ull start, ull end, ull* OddSum) {
    for (ull i = start; i <= end; ++i){
        if (i & 1){
            (*OddSum) += i;
        }
    }
}

int main() {
    
    ull start = 0, end = 1900000000;

    ull OddSum = 0;
    ull EvenSum = 0;
    
    auto startTime = high_resolution_clock::now();

    // // WITH THREAD
    std::thread t1(findEven, start, end, &(EvenSum)); //what happens here is that they are together at the same time instead of
    std::thread t2(findOdd, start, end, &(OddSum));//each one of them consuming 2 seconds now they take 2 seconds together

    t1.join();
    t2.join();

    // // WITHOUT THREAD
     //findEven(start,end, &EvenSum);
     //findOdd(start, end, &OddSum);
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "OddSum : " << OddSum << endl;
    cout << "EvenSum : " << EvenSum << endl;

    cout << "Sec: " << duration.count()/1000000 << endl;

    return 0;
}
*/

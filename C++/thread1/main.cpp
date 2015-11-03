#include <cstdio>
#include <atomic>
#include<thread>
#include<stdlib.h>
#include<time.h>
using namespace std;

atomic<int> x, y;

void f1() {
    x.store(1, memory_order_release);
    if (y.load(memory_order_acquire) == 1) {
        printf("f1 says: All done!\n");
    }
}

void f2() {
    y.store(1, memory_order_release);
    if (x.load(memory_order_acquire) == 1) {
        printf("f2 says: All done!\n");
    }
}

int main() {
     srand(time(NULL));
     std::thread t1(f1);
     std::thread t2(f2);
     t1.join();
     t2.join();
     printf("main: finished.\n");
     return 0;
}


#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;
int main()
{
    long memory = 1;
    while (memory != 1073741824) {
        auto start = chrono::system_clock::now();
        char* mem;
        mem = (char*)malloc(memory);
        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        cout << memory << ", ";
        cout << elapsed_seconds.count() << ", ";

        start = chrono::system_clock::now();
        free(mem);
        end = chrono::system_clock::now();
        elapsed_seconds = end - start;
        cout << elapsed_seconds.count() << "\n";

        memory *= 2;
    }
}

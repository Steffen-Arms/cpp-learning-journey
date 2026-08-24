#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

int main()
{
    std::vector<bool> c(100000);
    c[95000] = true;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000; ++i)
    {
        auto it = std::find(c.begin(), c.end(), true);
        asm volatile("" : : "r"(&it) : "memory"); // gegen Wegoptimieren
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(end - start).count()
              << " ms\n";
}

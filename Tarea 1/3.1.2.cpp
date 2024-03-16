#include <iostream>
#include <cstdlib>

int* gpVect = nullptr;
int gnCount = 0;
int gnMax = 0;

void Insert(int elem) {
    if (gnCount == gnMax) {
        Resize();
    }
    gpVect[gnCount++] = elem;
}

void Resize() {
    const int delta = 10;
    gpVect = (int*)realloc(gpVect, sizeof(int) * (gnMax + delta));
    gnMax += delta;
}

int main() {
    Insert(42);
    Insert(17);

    std::cout << "First element: " << gpVect[0] << std::endl;
    std::cout << "Second element: " << gpVect[1] << std::endl;

    free(gpVect);
    return 0;
}

// test.cpp
#include <iostream>
#include <cassert>
using namespace std;

// small testable function (example utility used by system)
int sumCredits(int a, int b) {
    return a + b;
}

void test_sumCredits() {
    // basic test cases
    assert(sumCredits(3, 4) == 7);
    assert(sumCredits(0, 0) == 0);
    assert(sumCredits(5, 1) == 6);
}

int main() {
    cout << "Running tests...\n";
    test_sumCredits();
    cout << "All tests passed.\n";
    return 0;
}


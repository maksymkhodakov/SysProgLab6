#include <bits/stdc++.h>
using namespace std;

// 1) commands to get a flame graph
// git clone https://github.com/brendangregg/FlameGraph
// perf record -F 50 --call-graph dwarf ./my_prog arg1 arg2
// perf script | /home/jovakinn/CLionProjects/flame/FlameGraph/stackcollapse-perf.pl | /home/jovakinn/CLionProjects/flame/FlameGraph/stackcollapse-recursive.pl | /home/jovakinn/CLionProjects/flame/FlameGraph/flamegraph.pl > outMain.svg


// Function to return gcd of a and b
int gcd(int a, int b) {

    // Find Minimum of a and b
    int result = min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}

// Driver code
int main() {

    for (int a = 100; a < 1500; a++) {
        for (int b = 1500; b >= 1000; b--) {
            cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << endl;
        }
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

// Function to return gcd of a and b using the Euclidean algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
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

#include <bits/stdc++.h>
using namespace std;

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

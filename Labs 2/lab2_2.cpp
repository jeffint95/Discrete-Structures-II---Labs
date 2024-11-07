// Jeffrey Interiano
// CISC 2100

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Inverse Modulo

// function for modular arithmetic to handle negative values
int mod(int x, int n) {
    return (x % n + n) % n;
}

// extended Euclidean Algorithm for GCD and finding coefficients s and t
int ExtendedEuclidAlgGCD(int a, int b, int &s, int &t) {
    if (b == 0) {
        s = 1;
        t = 0;
        return a;
    }
    
    int s1, t1;
    int gcd = ExtendedEuclidAlgGCD(b, a % b, s1, t1);
    
    s = t1;
    t = s1 - (a / b) * t1;
    
    return gcd;
}

// function to find modular inverse
int InverseMod(int a, int n) {
    int s, t;
    int d = ExtendedEuclidAlgGCD(a, n, s, t);
    if (d == 1) {
        // Use mod to make sure s is between 0 and n - 1
        return mod(s, n);
    } else {
        cout << "a and n are not relatively prime!" << endl;
        return -1; // indicates no modular inverse exists
    }
}

int main() {
    int a, n;
    cout << "Enter a non-negative integer a and n > 1 (a <= n): ";
    cin >> a >> n;

    int inverse = InverseMod(a, n);
    if (inverse != -1) {
        cout << "The modular inverse of " << a << " modulo " << n << " is: " << inverse << endl;
        // verification
        cout << "Verification: (" << a << " * " << inverse << ") % " << n << " = " << (a * inverse % n) << endl;
    }

    return 0;
}
// Jeffrey Interiano
// CISC 2100

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/* Instruction: Write a C++/Python program following the instructions below. Please follow the
order of the tasks given below, and write one function a time, test it, and then move on to next
function. Your main() function should just include codes that call these functions one by one with
some test cases. */

// Euclidean Algorithm and Extended Euclidean Algorithm

// find the GCD
int EuclidAlgGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

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

int main() {
    int a, b;
    
    cout << "Enter two non-negative integers (a >= b >= 0): ";
    cin >> a >> b;

    // test Euclidean Algorithm
    int gcd = EuclidAlgGCD(a, b);
    cout << "GCD (using Euclidean algorithm) of " << a << " and " << b << " is: " << gcd << endl;

    // test Extended Euclidean Algorithm
    int s, t;
    gcd = ExtendedEuclidAlgGCD(a, b, s, t);
    cout << "GCD (using Extended Euclidean algorithm) of " << a << " and " << b << " is: " << gcd << endl;
    cout << "The coefficients s and t are: " << s << " and " << t << endl;
    cout << "Verification: " << gcd << " = " << s << " * " << a << " + " << t << " * " << b << endl;

    return 0;
}
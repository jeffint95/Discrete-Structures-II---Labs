// Jeffrey Interiano
// CISC 2100

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Find Relative Prime

// euclidean Algorithm to find GCD (reused from Q1)
int EuclidAlgGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// function to find a number greater than 1 that is relatively prime to n
int RelativePrime(int n) {
    for (int candidate = 2; candidate < n; ++candidate) {
        if (EuclidAlgGCD(candidate, n) == 1) {
            return candidate; // Return the first number that is relatively prime to n
        }
    }
    return -1; // fallback if no relative prime is found, though there should always be one
}

int main() {
    int n;
    cout << "Enter an integer n (> 1): ";
    cin >> n;

    int relativePrime = RelativePrime(n);
    if (relativePrime != -1) {
        cout << "A number relatively prime to " << n << " is: " << relativePrime << endl;
    } else {
        cout << "No relative prime number found (shouldn't happen for n > 1)" << endl;
    }

    return 0;
}
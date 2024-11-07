// Jeffrey Interiano
// CISC 2100

#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
using namespace std;

// RSA Algorithm

// Euclidean Algorithm to find GCD (reused from Q1)
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
    return -1;
}

// function for modular arithmetic to handle negative values
int mod(int x, int n) {
    return (x % n + n) % n;
}

// fxtended Euclidean Algorithm for GCD and finding coefficients s and t
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
        // use mod to make sure s is between 0 and n - 1
        return mod(s, n);
    } else {
        cout << "a and n are not relatively prime!" << endl;
        return -1; // indicates no modular inverse exists
    }
}

// RSA Encode function: Returns M^e mod PQ
int Encode(int M, int e, int PQ) {
    int result = 1;
    M = M % PQ;
    while (e > 0) {
        if (e % 2 == 1) {
            result = (result * M) % PQ;
        }
        e = e >> 1;
        M = (M * M) % PQ;
    }
    return result;
}

// RSA Decode function: Returns C^d mod PQ
int Decode(int C, int d, int PQ) {
    int result = 1;
    C = C % PQ;
    while (d > 0) {
        if (d % 2 == 1) {
            result = (result * C) % PQ;
        }
        d = d >> 1;
        C = (C * C) % PQ;
    }
    return result;
}

int main() {
    const int P = 23;
    const int Q = 17;
    int PQ = P * Q;

    int phiPQ = (P - 1) * (Q - 1);

    // Step 2: Find e
    int e = RelativePrime(phiPQ);
    cout << "Chosen e (relatively prime to " << phiPQ << ") is: " << e << endl;

    // Step 3: Calculate d
    int d = InverseMod(e, phiPQ);
    cout << "Calculated d (modular inverse of e mod " << phiPQ << ") is: " << d << endl;

    // Step 4: RSA Encode and Decode functions
    int M;
    cout << "Enter an integer that is smaller than " << PQ << ": ";
    cin >> M;
    assert(M < PQ); // ensure M is within the bounds

    int C = Encode(M, e, PQ);  // encrypt the message
    cout << "Encoded message (C) is: " << C << endl;

    int M1 = Decode(C, d, PQ);  // decrypt the message
    cout << "Decoded message (M1) is: " << M1 << endl;

    // Step 6: Verify RSA algorithm works
    assert(M == M1);
    cout << "RSA verification successful! Original message M = " << M << ", Decoded message M1 = " << M1 << endl;

    return 0;
}
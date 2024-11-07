// Jeffrey Interiano
// CISC 2100

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Write a function to calculate modular exponents

// Pseudocode for recursive implementation:

// recursive implementation
int ExponentMod(int a, int e, int n)
{
    if (e == 0)
        return 1; // base case: a^0 = 1
    if (e == 1)
        return a % n; // base case: a^1 = a mod n

    // if e is even
    if (e % 2 == 0)
    {
        int result = ExponentMod(a, e / 2, n);
        return (result * result) % n;
    }
    // if e is odd
    else
    {
        int result = ExponentMod(a, e - 1, n);
        return (result * (a % n)) % n;
    }
}

int main()
{
    int a = 5, e = 13, n = 23;
    cout << "Recursive ExponentMod(" << a << ", " << e << ", " << n << ") = "
         << ExponentMod(a, e, n) << endl;
    return 0;
}

// Pseudocode for non-recursive implementation:

// iterative implementation of ExponentMod
int ExponentModIterative(int a, int e, int n)
{
    int result = 1;   // initialize result
    int base = a % n; // a^1 mod n

    while (e > 0)
    {
        // if the last bit of e is 1, multiply the result with the current base
        if (e & 1)
        {
            result = (result * base) % n;
        }
        // square the base
        base = (base * base) % n;
        // right shift e to process the next bit
        e >>= 1;
    }
    return result;
}

int main()
{
    int a = 5, e = 13, n = 23;
    cout << "Iterative ExponentMod(" << a << ", " << e << ", " << n << ") = "
         << ExponentModIterative(a, e, n) << endl;
    return 0;
}
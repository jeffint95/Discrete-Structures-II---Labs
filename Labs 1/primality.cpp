// Jeffrey Interiano
// CISC 2100

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Write a function to test primality

bool IsPrime(int n)
{
    // precondition: n must be greater than 1
    if (n <= 1)
    {
        return false;
    }

    // check if n has any divisor other than 1 and itself
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false; // n is not a prime number
        }
    }

    return true; // n is prime
}

int main()
{
    cout << IsPrime(5) << endl;
    cout << IsPrime(10) << endl;
    cout << IsPrime(29) << endl;
    cout << IsPrime(49) << endl;
    return 0;
}
// Jeffrey Interiano
// CISC 2100

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Write a function to display prime factorization of an integer

void PrimeFactorization(int n)
{
    // precondition: n must be greater than 1
    if (n <= 1)
    {
        cout << "n must be greater than 1." << endl;
        return;
    }

    // track the count of each prime factor
    int count;

    // check divisibility by 2 first
    count = 0;
    while (n % 2 == 0)
    {
        n /= 2;
        count++;
    }
    if (count > 0)
    {
        cout << "2(" << count << ")";
    }

    // check divisibility by odd numbers from 3 onward
    for (int i = 3; i * i <= n; i += 2)
    {
        count = 0;
        while (n % i == 0)
        {
            n /= i;
            count++;
        }
        if (count > 0)
        {
            cout << i << "(" << count << ")";
        }
    }

    // if n is a prime number greater than 2 at this point, it is a prime factor
    if (n > 2)
    {
        cout << n << "(1)";
    }

    cout << endl;
}

int main()
{
    int n = 100;
    PrimeFactorization(n);

    n = 360;
    PrimeFactorization(n);

    return 0;
}

// Jeffrey Interiano
// CISC 2100

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Find the first n prime numbers

bool IsPrime(int n)
{
    if (n <= 1)s
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> FindFirstNPrimes(int n)
{
    vector<int> primes;
    int number = 2; // start checking from the smallest prime number

    while (primes.size() < n)
    {
        if (IsPrime(number))
        {
            primes.push_back(number); // add prime number to the list
        }
        number++; // check the next number
    }

    return primes;
}

int main()
{
    int n = 300;
    vector<int> primes = FindFirstNPrimes(n);

    // print the first n prime numbers
    for (int prime : primes)
    {
        cout << prime << " ";
    }

    return 0;
}
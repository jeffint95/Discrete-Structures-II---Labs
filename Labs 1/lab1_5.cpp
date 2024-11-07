// Jeffrey Interiano
// CISC 2100

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// Implement function to perform modular arithmetics

// function for modular addition
int AddMod(int a, int b, int n)
{
    return (a + b) % n;
}

// function for modular subtraction
int SubMod(int a, int b, int n)
{
    return (a - b + n) % n;
}

// function for modular multiplication
int MulMod(int a, int b, int n)
{
    return (a * b) % n;
}

// function to display modular multiplication table
void DisplayModMulTable(int n)
{
    cout << "Modular-" << n << " multiplication table:" << endl;

    // print header row
    cout << "   ";
    for (int i = 1; i < n; ++i)
    {
        cout << i << " ";
    }
    cout << endl;

    // print the table
    for (int i = 1; i < n; ++i)
    {
        cout << i << " ";
        for (int j = 1; j < n; ++j)
        {
            cout << MulMod(i, j, n) << " ";
        }
        cout << endl;
    }
}

// main function to test the implementations
int main()
{
    int a = 7, b = 3, n = 5;

    // test modular addition
    cout << "AddMod(" << a << ", " << b << ", " << n << ") = " << AddMod(a, b, n) << endl;

    // test modular subtraction
    cout << "SubMod(" << a << ", " << b << ", " << n << ") = " << SubMod(a, b, n) << endl;

    // test modular multiplication
    cout << "MulMod(" << a << ", " << b << ", " << n << ") = " << MulMod(a, b, n) << endl;

    // display the modular multiplication table for the given n
    DisplayModMulTable(n);

    return 0;
}

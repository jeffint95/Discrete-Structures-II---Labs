#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

/* Instruction: Write a C++/Python program following the instructions below. Please follow the
order of the tasks given below, and write one function a time, test it, and then move on to next
function. Your main() function should just include codes that call these functions one by one with
some test cases */

// Modular arithmetic

int mod(int a, int n)
{
    // check if n is greater than 1
    if (n <= 1)
    {
        throw invalid_argument("n must be greater than 1"); // if n is greater than 1 throw
    }

    // using the modulo operator to get the remainder
    int result = a % n;

    // if the result is negative, adjust it to be within the range [0, n)
    if (result < 0)
    {
        result += n;
    }

    return result;
}

int main()
{
    // test cases
    cout << "mod(-1, 3) = " << mod(-1, 3) << endl;
    cout << "mod(5, 3) = " << mod(5, 3) << endl;
    cout << "mod(-5, 3) = " << mod(-5, 3) << endl;
    cout << "mod(10, 4) = " << mod(10, 4) << endl;
    return 0;
}

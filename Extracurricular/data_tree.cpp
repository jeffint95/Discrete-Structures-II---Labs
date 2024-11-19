#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Data Communications and Network Problem using Data Trees

/* Sixteen stations, numbered 0 through 15, are contending for the use of a shared
channel by using the adaptive tree walk protocol. If all the stations whose addresses are
prime numbers suddenly become ready at once, how many slots are needed to resolve the
contention? */

// function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <=n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// function to calculate the number of slots required
int calculateslots(int numContenders) {

    // the number of slots needed is the ceiling of log2(numContenders)
    return static_cast<int>(ceil(log2(numContenders)));
}

int main () {
    // total number of stations (addresses from 0 to 15)
    const int numStations = 16;

    // find the stations with prime addresses
    vector<int> primeStations;
    for (int i = 0; i < numStations; i++) {
        if (isPrime(i)) {
            primeStations.push_back(i);
        }
    }

    // number of contenders (stations with prime addresses)
    int numContenders = primeStations.size();

    // calculate the number of slots required to resolve contention
    int slotsRequired = calculateslots(numContenders);

    // output the result
    cout << "Stations with prime-numbered addresses: ";
    for (int station : primeStations) {
        cout << station << " ";
    }
    cout << "\n";

    cout << "Number of slots required to resolve contention: " << slotsRequired << endl;
}
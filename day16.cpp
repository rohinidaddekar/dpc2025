#include <iostream>
using namespace std;

// Function to calculate GCD using Euclidean algorithm
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM
long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;  // To prevent overflow
}

int main() {
    long long N, M;
    cin >> N >> M;

    cout << lcm(N, M) << endl;

    return 0;
}

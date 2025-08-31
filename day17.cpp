#include <iostream>
#include <vector>
using namespace std;

vector<int> primeFactorization(int N) {
    vector<int> factors;

    // Divide by 2 until N becomes odd
    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }

    // Divide by odd numbers starting from 3
    for (int i = 3; i * 1LL * i <= N; i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }

    // If N is still greater than 2, then it is prime
    if (N > 2) {
        factors.push_back(N);
    }

    return factors;
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;

    vector<int> result = primeFactorization(N);

    cout << "Prime factors: [";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

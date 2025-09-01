#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == n / i) 
                count++;  // perfect square case, count only once
            else 
                count += 2;  // count both i and n/i
        }
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countDivisors(N) << endl;
    return 0;
}

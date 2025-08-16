#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int>& arr, int n) {
    // Calculate expected sum of numbers from 1 to n
    int totalSum = n * (n + 1) / 2;

    // Calculate sum of given array
    int arrSum = 0;
    for (int num : arr) {
        arrSum += num;
    }

    // Missing number = totalSum - arrSum
    return totalSum - arrSum;
}

int main() {
    vector<int> arr = {1, 2, 4, 5};  // Example
    int n = arr.size() + 1;  // Since one number is missing

    cout << "Missing number: " << findMissingNumber(arr, n) << endl;

    return 0;
}

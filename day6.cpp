#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    unordered_map<int, vector<int>> prefixMap;
    vector<pair<int, int>> result;
    int prefixSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        // Case 1: If prefix sum becomes 0, then subarray (0..i) has sum 0
        if (prefixSum == 0) {
            result.push_back({0, i});
        }

        // Case 2: If prefixSum is already seen before
        if (prefixMap.find(prefixSum) != prefixMap.end()) {
            for (int startIndex : prefixMap[prefixSum]) {
                result.push_back({startIndex + 1, i});
            }
        }

        // Store current index in map
        prefixMap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int, int>> zeroSumSubarrays = findZeroSumSubarrays(arr);

    if (zeroSumSubarrays.empty()) {
        cout << "No subarray found with sum 0" << endl;
    } else {
        cout << "Subarrays with zero sum are: " << endl;
        for (auto& p : zeroSumSubarrays) {
            cout << "(" << p.first << ", " << p.second << ")" << endl;
        }
    }

    return 0;
}

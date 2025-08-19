#include <iostream>
#include <vector>
#include <algorithm> // for reverse
using namespace std;

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;
    int maxFromRight = arr[n - 1];

    // Last element is always a leader
    leaders.push_back(maxFromRight);

    // Traverse from right to left
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= maxFromRight) {
            leaders.push_back(arr[i]);
            maxFromRight = arr[i];
        }
    }

    // Reverse to maintain original order
    reverse(leaders.begin(), leaders.end());

    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> result = findLeaders(arr);

    cout << "Leaders: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

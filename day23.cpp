#include <bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq; // stores indices of elements
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        // Remove indices out of current window
        if (!dq.empty() && dq.front() == i - k)
            dq.pop_front();

        // Remove smaller elements from the back
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        // Add current element index
        dq.push_back(i);

        // Window is valid only after i >= k-1
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }
    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = maxSlidingWindow(arr, k);

    cout << "Output: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}

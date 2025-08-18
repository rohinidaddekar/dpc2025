#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Function to calculate next gap
int nextGap(int gap) {
    if (gap <= 1) return 0;
    return (gap / 2) + (gap % 2);
}

// Function to merge two sorted arrays in-place
void mergeArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int gap = m + n;

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap)) {
        int i, j;

        // Compare elements in first array
        for (i = 0; i + gap < m; i++) {
            if (arr1[i] > arr1[i + gap])
                swap(arr1[i], arr1[i + gap]);
        }

        // Compare elements between arr1 and arr2
        for (j = (gap > m) ? (gap - m) : 0; i < m && j < n; i++, j++) {
            if (arr1[i] > arr2[j])
                swap(arr1[i], arr2[j]);
        }

        // Compare elements in second array
        if (j < n) {
            for (j = 0; j + gap < n; j++) {
                if (arr2[j] > arr2[j + gap])
                    swap(arr2[j], arr2[j + gap]);
            }
        }
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    mergeArrays(arr1, arr2, arr1.size(), arr2.size());

    cout << "arr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << endl;

    cout << "arr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}

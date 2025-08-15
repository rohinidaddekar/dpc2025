#include<iostream>
using namespace std;

void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;
    
    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                swap(arr[low], arr[mid]);
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(arr[mid], arr[high]);
                high--;
                break;
        }
    }
}

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[] = {0, 1, 2, 1, 0, 2, 1, 0};
    int n = sizeof(a) / sizeof(a[0]);
    
    cout << "Before sort: ";
    printArr(a, n);
    
    sort012(a, n);
    
    cout << "After sort: ";
    printArr(a, n);
    
    return 0;
}

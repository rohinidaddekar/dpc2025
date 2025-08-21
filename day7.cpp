#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) return 0;

    int left = 0, right = n - 1;   // Two pointers
    int leftMax = 0, rightMax = 0; // Track maximum heights from both sides
    int water = 0;

    while (left < right) {
        if (height[left] < height[right]) {
            // Water depends on leftMax
            if (height[left] >= leftMax) {
                leftMax = height[left]; 
            } else {
                water += leftMax - height[left];
            }
            left++;
        } else {
            // Water depends on rightMax
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                water += rightMax - height[right];
            }
            right--;
        }
    }

    return water;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped Water: " << trap(height) << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums) {
    // Phase 1: Finding the intersection point
    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];         
        fast = nums[nums[fast]];   
    } while (slow != fast);

    // Phase 2: Finding the entrance to the cycle (duplicate number)
    slow = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow; 
}

int main() {
    vector<int> arr = {3, 1, 3, 4, 2};

    int duplicate = findDuplicate(arr);
    cout << "Duplicate number: " << duplicate << endl;

    return 0;
}

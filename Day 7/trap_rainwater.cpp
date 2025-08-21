#include<iostream>
#include<vector>
using namespace std;

int trap(vector<int>& arr) {
    int n = arr.size();
    if (n < 3) return 0; 

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right) {
        if (arr[left] <= arr[right]) {
            if (arr[left] >= leftMax) {
                leftMax = arr[left];
            } else {
                water += leftMax - arr[left];
            }
            left++;
        } else {
            if (arr[right] >= rightMax) {
                rightMax = arr[right];
            } else {
                water += rightMax - arr[right];
            }
            right--;
        }
    }
    return water;
}

int main() {
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped Rain Water = " << trap(arr) << endl; 
    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstElementToRepeatKTimes(const vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    for (int x : arr) {
        freq[x]++;
        if (freq[x] == k) {
            return x; 
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int k = 2;

    cout << firstElementToRepeatKTimes(arr, k) << endl;  
    return 0;
}

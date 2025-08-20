#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<pair<int,int>> findZeroSumSubarrays(vector<int>& arr) {
    unordered_map<int, vector<int>> prefixMap;
    vector<pair<int,int>> result;

    int prefixSum = 0;

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (prefixSum == 0) {
            result.push_back({0, i});
        }

        if (prefixMap.find(prefixSum) != prefixMap.end()) {
            for (int startIndex : prefixMap[prefixSum]) {
                result.push_back({startIndex + 1, i});
            }
        }

        prefixMap[prefixSum].push_back(i);
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int,int>> subarrays = findZeroSumSubarrays(arr);

    cout << "Zero-sum subarrays are:\n";
    for (auto &p : subarrays) {
        cout << "[" << p.first << ", " << p.second << "]\n";
    }
    return 0;
}

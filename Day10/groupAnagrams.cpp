#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    
    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end()); // sorted key
        mp[key].push_back(s);
    }
    
    vector<vector<string>> result;
    for (auto& it : mp) {
        result.push_back(it.second);
    }
    return result;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";
    for (auto& group : ans) {
        cout << "[ ";
        for (auto& word : group) cout << word << " ";
        cout << "]\n";
    }
    return 0;
}

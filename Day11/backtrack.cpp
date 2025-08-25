#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void backtrack(string &s, vector<bool> &used, string &curr, vector<string> &result) {
    if (curr.size() == s.size()) {
        result.push_back(curr);
        return;
    }
    for (int i = 0; i < s.size(); i++) {
        if (used[i]) continue;

        // Skip duplicates
        if (i > 0 && s[i] == s[i-1] && !used[i-1]) continue;

        used[i] = true;
        curr.push_back(s[i]);
        backtrack(s, used, curr, result);
        curr.pop_back();
        used[i] = false;
    }
}

vector<string> permuteUnique(string s) {
    sort(s.begin(), s.end());  // sort to handle duplicates
    vector<string> result;
    vector<bool> used(s.size(), false);
    string curr = "";
    backtrack(s, used, curr, result);
    return result;
}

int main() {
    string s = "abc";
    vector<string> ans = permuteUnique(s);

    cout << "Permutations:\n";
    for (auto &p : ans) cout << p << "\n";
    return 0;
}

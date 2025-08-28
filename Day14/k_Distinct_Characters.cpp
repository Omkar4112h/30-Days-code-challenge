#include<iostream>
#include<string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int atMostK(string &s, int k) {
        int n = s.size();
        int left = 0, result = 0;
        unordered_map<char, int> freq;

        for (int right = 0; right < n; right++) {
            freq[s[right]]++;

            while ((int)freq.size() > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    freq.erase(s[left]);
                left++;
            }

            result += (right - left + 1);
        }
        return result;
    }

    int substrCount(string s, int k) {
        return atMostK(s, k) - atMostK(s, k - 1);
    }
};

int main() {
    string s = "pqpqs";
    int k = 2;
    Solution sol;
    cout << sol.substrCount(s, k) << endl; // Output: 7
    return 0;
}

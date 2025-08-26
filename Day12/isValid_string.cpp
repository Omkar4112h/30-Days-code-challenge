#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> bracket = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char ch : s) {
        if (bracket.count(ch)) { // if ch is a closing bracket
            if (st.empty() || st.top() != bracket[ch]) {
                return false;
            }
            st.pop();
        } else {
            st.push(ch); // opening bracket
        }
    }
    return st.empty();
}

int main() {
    string s = "[{()}]";
    if (isValid(s))
        cout << "Valid" << endl;
    else
        cout << "Invalid" << endl;
    return 0;
}

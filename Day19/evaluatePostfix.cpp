#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int evaluatePostfix(const string &expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b);  
        } else {
            st.push(stoi(token)); 
        }
    }
    return st.top();
}

int main() {
    string expr = "2 1 + 3 *";
    cout << evaluatePostfix(expr) << endl; 
    return 0;
}

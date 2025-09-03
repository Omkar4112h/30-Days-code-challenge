#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int> &st, int x) {
    if (st.empty() || st.top() <= x) {
        st.push(x);
        return;
    }
    int top = st.top();
    st.pop();
    insertSorted(st, x);
    st.push(top);
}

void sortStack(stack<int> &st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, top);
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sortStack(st);

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}

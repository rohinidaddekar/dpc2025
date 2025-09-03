#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void insertSorted(stack<int>& st, int element) {
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }
    int topElement = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(topElement);
}

void sortStack(stack<int>& st) {
    if (st.empty()) return;
    int topElement = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, topElement);
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    sortStack(st);

    // Store stack elements in vector for proper display
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    // Print in correct ascending order
    cout << "[";
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i];
        if (i > 0) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}

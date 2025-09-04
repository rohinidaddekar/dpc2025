#include <iostream>
#include <stack>
using namespace std;

// Function to insert element at the bottom of the stack
void insertAtBottom(stack<int> &st, int x) {
    if (st.empty()) {
        st.push(x);
        return;
    }
    
    int topElement = st.top();
    st.pop();
    insertAtBottom(st, x);
    st.push(topElement);
}

// Function to reverse the stack using recursion
void reverseStack(stack<int> &st) {
    if (st.empty()) return;

    int topElement = st.top();
    st.pop();
    
    reverseStack(st);
    
    insertAtBottom(st, topElement);
}

// Function to print stack from bottom to top
void printStackBottomToTop(stack<int> st) {
    if (st.empty()) return;
    
    int x = st.top();
    st.pop();
    
    printStackBottomToTop(st);  // recurse down
    cout << x << " ";           // print after recursion (bottom first)
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack (bottom to top): ";
    printStackBottomToTop(st);
    cout << endl;

    reverseStack(st);

    cout << "Reversed Stack (bottom to top): ";
    printStackBottomToTop(st);
    cout << endl;

    return 0;
}

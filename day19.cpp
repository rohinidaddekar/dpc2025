#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string expression) {
    stack<int> st;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        // If it's an operator
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b);  // integer division
        }
        else {
            // Otherwise it's a number (convert string to int)
            st.push(stoi(token));
        }
    }

    return st.top();
}

int main() {
    string expr = "2 1 + 3 *";
    cout << evaluatePostfix(expr) << endl;  // Output: 9
    return 0;
}

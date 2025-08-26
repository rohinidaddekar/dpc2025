#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for(char c : s) {
        if(c == '(' || c == '{' || c == '[') {
            st.push(c); // push opening brackets
        } 
        else {
            if(st.empty()) return false; // no opening bracket to match

            char top = st.top();
            st.pop();

            // check matching pairs
            if((c == ')' && top != '(') ||
               (c == '}' && top != '{') ||
               (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty(); // valid if no unmatched opening brackets
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if(isValid(s)) 
        cout << "true\n";
    else 
        cout << "false\n";

    return 0;
}

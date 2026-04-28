#include <bits/stdc++.h>
using namespace std;

int prec(char opr) {
    if (opr == '^') return 3;
    else if (opr == '*' || opr == '/') return 2;
    else if (opr == '+' || opr == '-') return 1;
    else return 0;
}

bool opr(char x) {
    return (x == '+' || x == '-' || x == '*' || x == '/' || x == '^');
}

string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {postfix += c;}
        else if (c == '(') {st.push(c);}
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else if (opr(c)) {
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix;

    cout << "Infix: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    
    cout << "Postfix: " << postfix << endl;

    return 0;
}
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string st;
    getline(cin, st);

    stack<int> s;
    for (int i = 0; i < st.length(); i++) {
        char c = st[i];

        if ('0' <= c && c <= '9') {
            s.push(c - '0');
        }
        else {
            int a, b;
            a = s.top();
            s.pop();
            b = s.top();
            s.pop();

            if (c == '+') {
                s.push(b + a);
            }
            else if (c == '-') {
                s.push(b - a);
            }
            else if (c == '*') {
                s.push(b * a);
            }
            else if (c == '/') {
                s.push(b / a);
            }

        }
    }

    cout << s.top();
}

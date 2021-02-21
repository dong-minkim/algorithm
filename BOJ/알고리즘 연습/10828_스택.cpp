#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<int> S;

    int num;
    cin >> num;

    for (int i = 0; i < num; i++) {
        int x;

        string str;
        cin >> str;
        if (str == "push") {
            cin >> x;
            S.push(x);
        }
        else if (str == "top") {
            if (S.empty()) {
                cout << "-1" << '\n';
            }
            else cout << S.top() << '\n';
        }
        else if (str == "pop") {
            if (S.empty()) {
                cout << "-1" << '\n';
            }
            else {
                cout << S.top() << '\n';
                S.pop();

            }
        }
        else if (str == "empty") {
            if (S.empty()) {
                cout << "1" << '\n';
            }
            else cout << "0" << '\n';
        }
        else if (str == "size") {
            cout << S.size() << '\n';
        }
    }
    return 0;
}
#include <iostream>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

string st;
stack<char> s;

int main(void)

{
    cin >> st;

    int temp = 1;
    bool flag = false;
    long long result = 0;
    

    for (int i = 0; i < st.size(); i++){
        if (st[i] == '('){
            temp *= 2;
            s.push('(');
        }
        else if (st[i] == '['){
            temp *= 3;
            s.push('[');
        }


        else if (st[i] == ')' && (s.empty() || s.top() != '(')){
            flag = true;
            break;
        }
        else if (st[i] == ']' && (s.empty() || s.top() != '[')){
            flag = true;
            break;
        }
        else if (st[i] == ')'){
            if (st[i - 1] == '(')
                result += temp;
            
            s.pop();
            temp /= 2;
        }

        else if (st[i] == ']'){
            if (st[i - 1] == '[')
                 result += temp;

            s.pop();
            temp /= 3;
        }
    }
    if (flag || !s.empty())
        cout << 0 << "\n";
    else
        cout << result << "\n";

    return 0;
}
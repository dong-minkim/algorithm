#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
    vector<int> mvp;
    int t;
    cin >> t;
    for (int i = 0; i < 4; i++) {
        int num;
        cin >> num;
        mvp.push_back(num);
    }
    string s;
    cin >> s;
    int money_;
    vector<int> money;
    money.resize(t);
    for (int i = 0; i < t; i++) {
        if (i == 0) {
            if (s[i] == 'B' || s[i] == 'b') money.push_back(mvp[0] - 1);
            else if (s[i] == 'S' || s[i] == 's') money.push_back(mvp[1] - 1);
            else if (s[i] == 'G' || s[i] == 'g') money.push_back(mvp[2] - 1);
            else if (s[i] == 'P' || s[i] == 'p') money.push_back(mvp[3] - 1);
            else money.push_back(mvp[3]);
        }

        else {
            if (s[i] == 'B' || s[i] == 'b') {
                money_ = (mvp[0] - 1) - money.back();
                money.push_back(money_);
            }
            else if (s[i] == 'S' || s[i] == 's') {
                money_ = (mvp[1] - 1) - money.back();
                money.push_back(money_);
            }
            else if (s[i] == 'G' || s[i] == 'g') {
                money_ = (mvp[2] - 1) - money.back();
                money.push_back(money_);
            }
            else if (s[i] == 'P' || s[i] == 'p') {
                money_ = (mvp[3] - 1) - money.back();
                money.push_back(money_);
            }
            else money.push_back(mvp[3]);
        }
    }

    int sum = 0;
    for (int i = 0; i < money.size(); i++) {
        sum += money[i];
    }
    cout << sum;

    return 0;
}
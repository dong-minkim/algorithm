#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
	FAST_IO;

    bool flag = false;
    char tmp;

    int x;
    cin >> x;

    string s;
    cin >> s;

    int mansize = 0, womansize = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'M') {
            int now = abs((mansize + 1) - womansize);
            if (now <= x) mansize++;
            else {
                if (!flag) {
                    tmp = 'M';
                    flag = true;
                }
                else {
                    break;
                }
            }
        }
        else {
            int now = abs(mansize - (womansize + 1));
            if (now <= x) womansize++;
            else {
                if (!flag) {
                    tmp = 'W';
                    flag = true;
                }
                else {
                    break;
                }
            }
        }

        if (flag) {
            if (tmp == 'M') {
                int now = abs((mansize + 1) - womansize);
                if (now <= x) {
                    mansize++;
                    flag = false;
                }
            }
            else {
                int now = abs(mansize - (womansize + 1));
                if (now <= x) {
                    womansize++;
                    flag = false;
                }
            }
        }
    }
    cout << mansize + womansize;

	return 0;
}
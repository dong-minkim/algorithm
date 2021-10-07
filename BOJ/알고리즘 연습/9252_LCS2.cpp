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

int n, m;
string s1, s2;
int dp[1005][1005];
string Answer;

int main() {
	FAST_IO;

    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i - 1] == s2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    int i = s1.size();
    int j = s2.size();
    while (dp[i][j]) {
        int now = dp[i][j];
        if (dp[i - 1][j] == now - 1 && dp[i][j - 1] == now - 1) {
           Answer += s1[i - 1]; i--; j--;
        }
        else if (dp[i - 1][j] == now - 1 && dp[i][j - 1] == now)j--;
        else if (dp[i - 1][j] == now)i--;
    }
    reverse(Answer.begin(), Answer.end());
    cout << dp[s1.size()][s2.size()] << "\n";
    cout << Answer << "\n";


	return 0;
}
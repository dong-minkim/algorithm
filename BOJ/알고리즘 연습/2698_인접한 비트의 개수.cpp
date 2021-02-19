#include<iostream>
#include<algorithm>

using namespace std;

long long dp[105][105][2] = { 0, };

int main()
{
	int testcase;
	int n, k;
	cin >> testcase;
	dp[1][0][0] = 1;
	dp[1][0][1] = 1;
	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
		}
	}


	for (int i = 0; i < testcase; i++) {
		cin >> n >> k;
		cout << dp[n][k][0] + dp[n][k][1] << '\n';
	}

	return 0;
}
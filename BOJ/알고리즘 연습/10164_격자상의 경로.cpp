#include<iostream>

using namespace std;

int dp[16][16] = { 0, };
int n, m, k;
int tmp = 0;
int main()
{
	cin >> n >> m >> k;

	//k가 있을때: 두 구간으로 나눠 경로를 곱해주면 된다.
	if (k != 0) {
		//k의 행과 열
		int mid_n, mid_m;
		mid_n = (k - 1) / m + 1;
		if (k % m == 0) mid_m = m;
		else mid_m = k % m;

		dp[0][1] = 1;
		for (int i = 1; i <= mid_n; i++) {
			for (int j = 1; j <= mid_m; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		tmp = dp[mid_n][mid_m];

		for (int i = 1; i <= mid_n; i++) {
			for (int j = 1; j <= mid_m; j++) {
				dp[i][j] = 0;
			}
		}

		dp[0][1] = 1;
		for (int i = 1; i <= n - mid_n + 1; i++) {
			for (int j = 1; j <= m - mid_m + 1; j++) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << tmp * dp[n - mid_n + 1][m - mid_m + 1];
	}
	//k가 없을때
	else {
		//첫행과 첫열에(dp[n][1] , dp[1][m]) 다 1을 넣어줘야하는 번거로움을
		//사이즈를 1칸 더 늘려(dp[0][1] or dp[1][0]) 점화식으로 첫행과 첫열에 1을 다 넣는다.
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 && j == 1) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		printf("%d\n", dp[n][m]);
	}

	return 0;
}
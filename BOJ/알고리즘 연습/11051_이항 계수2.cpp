#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[1001][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (i == j || j == 0) {
				arr[i][j] = 1;
			}
			else {
				//이항계수 합 법칙
				arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
			}

		}
	}

	cout << arr[n][k] % 10007 << '\n';

	return 0;
}
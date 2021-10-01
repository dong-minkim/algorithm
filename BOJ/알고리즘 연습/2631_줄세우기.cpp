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

int arr[201];
int n;
int dp[201];
int Answer = 0;

int main() {
	FAST_IO;

	cin >> n;
	for (int i = 1; i <= n; i++) { 
		cin >> arr[i];
		dp[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		Answer = max(Answer, dp[i]);

	}

	cout << n - Answer << '\n';

	return 0;
}
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

	int n;
	cin >> n;
	vector<int> v;
	int dp[100002] = { 0, };


	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
		if (i == 0) continue;
		if (v[i - 1] > num) dp[i] = dp[i - 1] + 1;
		else dp[i] = dp[i - 1];
	}

	cin >> n;
	
	while (n--) {
		int x, y;
		cin >> x >> y;
		cout << dp[y-1] - dp[x-1] << '\n';
	}

	return 0;
}
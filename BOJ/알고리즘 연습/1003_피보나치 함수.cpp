#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;
long long cnt[50] = { 0,1, };
long long fibo(int n) {
	if (n == 0 || n == 1) return cnt[n];
	else if (cnt[n] == 0) {
		cnt[n] = fibo(n - 1) + fibo(n - 2);
	}
	return cnt[n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	int num;
	for (int i = 0; i < t; i++) {
		cin >> num;
		if (num == 0) cout << "1 0" << '\n';
		else cout << fibo(num - 1) << ' ' << fibo(num) << '\n';
	}

	return 0;
}
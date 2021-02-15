#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
#define ull unsigned long long
using namespace std;
ull check(ull n) {
	return n * (n + (long long)1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--) {
		ull n;
		ull mid = (ull)1;
		cin >> n;
		ull left = (ull)1;
		ull right = sqrt(n) * 2;

		while (left <= right) {
			mid = (left + right) / (ull)2;
			if (check(mid) > 2 * n)
				right = mid - (ull)1;
			else {
				left = mid + (ull)1;
			}
		}
		if (check(mid) > 2 * n) mid--;
		cout << mid << '\n';
	}

	return 0;
}
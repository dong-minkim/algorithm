#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;


bool solution(long long num) {
	if (num == 3 || num == 6 || num == 10) return true;
	else if (num > 5) {
		long long left = 1;
		long long right = num / 3;
		long long mid = 0;
		while (left <= right) {
			mid = (left + right) / 2;
			long long des = mid * (mid + 1) / 2;

			if (des < num) left = mid + 1;
			else if (des > num) right = mid - 1;
			else if (des == num) return true;
			else break;
		}
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long a, b;
	long long cnt;
	long long order = 1;
	while (1) {
		cnt = 0;
		cin >> a >> b;

		if (b == 0) return 0;

		for (long long i = 2; i * i < b; i++) {
			if (i * i <= a) continue;
			if (solution(i * i - 1) == true)
				cnt++;
		}
		cout << "Case " << order << ": " << cnt << '\n';
		order++;
	}


	return 0;
}
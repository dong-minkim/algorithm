#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n;
	long long m;
	vector<long long> v;
	long long max = 0;
	long long result = 0;
	cin >> n >> m;
	for (long long i = 0; i < m; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
		if (max < num) {
			max = num;
		}
	}
	long long left = 1, right = max;

	while (left <= right) {

		long long sum = 0;
		long long mid = (left + right) / 2;
		for (int i = 0; i < m; i++) {
			sum += v[i] / mid;
			if (v[i] % mid != 0) sum += 1;
		}

		if (sum <= n) {
			right = mid - 1;
			result = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << result << '\n';


	return 0;
}
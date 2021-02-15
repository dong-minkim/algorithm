#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;
vector<int> v;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long n, m;
	long long right = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		if (right < num) right = num;
		v.push_back(num);
	}
	long long left = 1;

	while (left <= right) {
		long long sum = 0;
		long long mid = (left + right) / 2;
		for (int i = 0; i < v.size(); i++) {
			sum += v[i] / mid;
		}
		if (sum < m) {
			right = mid - 1;
		}
		else if (sum >= m) {
			left = mid + 1;
		}
	}
	cout << right;


	return 0;
}
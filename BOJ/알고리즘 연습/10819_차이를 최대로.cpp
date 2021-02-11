#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int> v;
	int n;
	int sum = 0;
	int max_ = -1;
	int num2;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	do {
		sum = 0;
		for (int i = 0; i < n - 1; i++) {
			num2 = v[i] - v[i + 1];
			if (num2 < 0) num2 = (-1) * num2;
			sum += num2;
			max_ = max(sum, max_);
		}
		//모든 순열을 다 돌려 max 값을 찾는다.
	} while (next_permutation(v.begin(), v.end()));

	cout << max_ << '\n';

	return 0;
}
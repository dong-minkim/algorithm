#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int n, k;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	cin >> k;
	int sum = 0;
	long long result = 0;

	int start = 0;
	int end = 0;  

	while (start < n) {
		if (sum <= k &&end<n) sum += v[end++];
		else {
			sum -= v[start++];
			
		}
		if (sum > k) result += (n - end + 1);
	}

	cout << result << '\n';

	return 0;
}
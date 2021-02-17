#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;
long long arr[11] = { 0,1,2,4, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		long long num;
		cin >> num;
		for (int i = 4; i <= num; i++) {
			arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		}
		cout << arr[num] << '\n';
	}

	return 0;
}

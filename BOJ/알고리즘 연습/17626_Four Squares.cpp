#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	int min_;
	cin >> n;

	vector<int> v(n + 1, 0);

	v[1] = 1;

	//v에 n까지 최소의 개수 채워 넣는다(dp)
	for (int i = 2; i <= n; i++) {
		min_ = 5;
		//수에서 제곱수를 빼어 최소 개수를 구한다. 
		for (int j = 1; j * j <= i; j++) {
			int temp = i - j * j;
			min_ = min(min_, v[temp]);
		}
		v[i] = min_ + 1;
	}
	cout << v[n] << '\n';

	return 0;
}
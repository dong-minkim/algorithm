#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	int n;
	cin >> n;

	int cnt = 0;

	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	for (int i = 0; i < n; i++) {
		int flag = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				if (v[i].first > v[j].first && v[i].second >= v[j].second) {
					flag = 1;
					break;
				}
				if (v[i].second > v[j].second && v[i].first >= v[j].first) {
					flag = 1;
					break;
				}
			}
		}
		if (!flag) cnt++;
	}
	cout << cnt << '\n';

	return 0;
}
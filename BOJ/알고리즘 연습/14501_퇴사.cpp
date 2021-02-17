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

	vector<int> day;
	vector<int> cost;
	vector<int> v;
	int num;
	cin >> num;
	v.resize(num + 1, 0);
	day.resize(num + 1, 0);
	cost.resize(num + 1, 0);

	for (int i = 0; i < num; i++) {
		cin >> day[i] >> cost[i];
	}
	for (int i = 0; i < num; i++) {
		if (i + day[i] > num) continue;
		if (v[i + day[i]] < v[i] + cost[i]) {
			v[i + day[i]] = v[i] + cost[i];
			for (int j = i + day[i] + 1; j <= num; j++) {
				if (v[j] < v[i + day[i]]) {
					v[j] = v[i + day[i]];
				}
			}
		}

	}
	cout << v[num] << '\n';


	return 0;
}
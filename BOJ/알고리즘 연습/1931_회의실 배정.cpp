#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
	FAST_IO;

	vector<pair<int, int>> time;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		time.push_back({ end,start });
	}
	sort(time.begin(), time.end());

	int Answer = 0;
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (tmp <= time[i].second) {
			tmp = time[i].first;
			Answer++;
		}
	}

	cout << Answer << '\n';

	return 0;
}
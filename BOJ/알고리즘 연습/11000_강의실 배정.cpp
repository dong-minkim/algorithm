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
	priority_queue<int,vector<int>,greater<int>> room;

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		time.push_back({ start, end });
	}

	sort(time.begin(), time.end());

	room.push(time[0].first);
	for (int i = 1; i < time.size(); i++) {
		if (room.top() > time[i].first) {
			room.push(time[i].second);
		}
		else{
			room.pop();
			room.push(time[i].second);
		}
	}

	cout << room.size() << '\n';

	return 0;
}
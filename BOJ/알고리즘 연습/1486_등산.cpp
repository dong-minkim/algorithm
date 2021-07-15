#include<iostream>
#include<cmath>
#include<vector>
#include<queue>

using namespace std;

int n, m, t, d;
long long map[26][26];
long long dist[26][26];
long long dist2[26][26];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
string str;
priority_queue<pair<long long,pair<long long, long long>>>pq;

void Input() {
	cin >> n >> m >> t >> d;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < m; j++) {
			if ('A' <= str[j] && str[j] <= 'Z') {
				map[i][j] = str[j] - 65;
			}
			else if ('a' <= str[j] && str[j] <= 'z') {
				map[i][j] = str[j] - 71;
			}
			dist[i][j] = 10000000;
			dist2[i][j] = 10000000;
		}
	}
}

bool Inside(long long y, long long x) {
	if (y >= 0 && y < n && x >= 0 && x < m) return true;
	else return false;
}

void go() {
	dist[0][0] = 0;
	pq.push({ 0,{0,0} });
	while (!pq.empty()) {
		long long now_cost = -pq.top().first;
		long long now_y = pq.top().second.first;
		long long now_x = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			long long Y = now_y + dy[i];
			long long X = now_x + dx[i];

			long long tmp_cost;
			if (Inside(Y, X)) {
				if (abs(map[Y][X] - map[now_y][now_x]) <= t) {
					if (map[Y][X] <= map[now_y][now_x]) tmp_cost = 1;
					else tmp_cost = pow((map[Y][X] - map[now_y][now_x]),2);
					
					if (dist[Y][X] > now_cost + tmp_cost) {
						dist[Y][X] = now_cost + tmp_cost;
						pq.push({ -dist[Y][X],{ Y, X } });
					}
				}
			}
		}

	}
}

void back() {
	dist2[0][0] = 0;
	pq.push({ 0,{0,0} });
	while (!pq.empty()) {
		long long now_cost = -pq.top().first;
		long long now_y = pq.top().second.first;
		long long now_x = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			long long Y = now_y + dy[i];
			long long X = now_x + dx[i];

			long long tmp_cost;
			if (Inside(Y, X)) {
				if (abs(map[Y][X] - map[now_y][now_x]) <= t) {
					if (map[Y][X] >= map[now_y][now_x]) tmp_cost = 1;
					else tmp_cost = pow((map[Y][X] - map[now_y][now_x]), 2);

					if (dist2[Y][X] > now_cost + tmp_cost) {
						dist2[Y][X] = now_cost + tmp_cost;
						pq.push({ -dist2[Y][X],{ Y, X } });
					}
				}
			}
		}

	}
}

int main()
{
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);

	Input();
	go();
	back();

	long long answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] + dist2[i][j] <= d) {
				answer = max(answer, map[i][j]);
			}
		}
	}
	cout << answer << '\n';

	return 0;
}
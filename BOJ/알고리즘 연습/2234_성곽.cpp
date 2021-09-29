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

int room[51][51] = { 0, };
bool visited[51][51];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };
int area;
int n, m;

int bfs(int a, int b) {
	queue<pair<int, int>>q;
	q.push({ a, b });
	visited[a][b] = true;
	int cnt = 1;

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		int bit = 1;

		for (int i = 0; i < 4; i++)
		{
			if (!(room[y][x] & bit))
			{
				int Y = y + dy[i];
				int X = x + dx[i];

				if (!(0 <= Y && Y < m && 0 <= X && X < n))
					continue;

				if (!visited[Y][X]) {

					cnt++;
					visited[Y][X] = true;
					q.push({ Y, X });
				}
			}
			bit <<= 1;
		}
	}
	return cnt;
}


int main() {
	FAST_IO;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> room[i][j];
		}
	}

	int room_cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				area = max(area, bfs(i, j));
				room_cnt++;
			}
		}
	}

	cout << room_cnt << '\n';
	cout << area << '\n';

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 1; k <= 8; k <<= 1) {
				if (room[i][j] & k) {
					memset(visited, false, sizeof(visited));
					room[i][j] -= k;
					area = max(area, bfs(i, j));
					room[i][j] += k;
				}
			}
		}
	}

	cout << area << '\n';

	return 0;
}

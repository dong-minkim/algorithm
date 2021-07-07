#include<iostream>
#include<queue>

using namespace std;

int r, c;
char map[51][51];
int visited[51][51] = { 0, };

queue<pair<int, int>> water;
queue<pair<int, int>> start;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0 ,0 };

void Input() {
	cin >> r >> c;

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') water.push({ i,j });
			if (map[i][j] == 'S') start.push({ i,j });
		}
	}
}

int bfs() {
	int cnt = 0;
	while (!start.empty()) {
		
		int water_size = water.size();
		while (water_size--) {
			int y = water.front().first;
			int x = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int Y = y + dy[i];
				int X = x + dx[i];

				if (Y < 0 || Y >= r || X < 0 || X >= c) continue;
				if (map[Y][X] == 'X' || map[Y][X] == 'D' || map[Y][X] == '*') continue;
				water.push({ Y,X });
				map[Y][X] = '*';
			}
		}

		int start_size = start.size();
		while (start_size--) {
			int y = start.front().first;
			int x = start.front().second;
			start.pop();

			if (map[y][x] == 'D') {
				cout << cnt << '\n';
				return 0;
			}

			visited[y][x] = 1;

			for (int i = 0; i < 4; i++) {
				int Y = y + dy[i];
				int X = x + dx[i];

				if (Y < 0 || Y >= r || X < 0 || X >= c) continue;
				if (map[Y][X] == 'X' || map[Y][X] == '*' || visited[Y][X]==1) continue;
				visited[Y][X] = 1;
				start.push({ Y,X });
			}
		}
		cnt++;
	}
	cout << "KAKTUS" << '\n';
	return 0;
}

int main() {

	Input();

	bfs();

	return 0;
}
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n, m;
int answer = 0;
int cnt;
int ice[301][301];
int copy_ice[301][301];
int visited[301][301];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

//입력
void Input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
		}
	}
}

void dfs(int y, int x) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i];
		int X = x + dx[i];
		if (0 <= Y && Y < n && 0 <= X && X < m) {
			if (ice[Y][X] > 0 && visited[Y][X] == 0) {
				dfs(Y, X);
			}
		}
	}
}

void melt(int y, int x) {
	int water = 0;
	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i];
		int X = x + dx[i];

		if (copy_ice[Y][X] == 0) water++;
	}
	ice[y][x] = copy_ice[y][x] - water;
	if (ice[y][x] < 0) ice[y][x] = 0;
}

int main()
{
	cin >> n >> m;

	Input();
	
	while (1) {
		
		memset(visited, 0, sizeof(visited));

		cnt = 0; //빙산차지 구역 수
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] > 0 && visited[i][j] == 0) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		
		if (cnt >= 2) {
			cout << answer << '\n';
			return 0;
		}

		if (cnt == 0) {
			cout << 0 << '\n';
			return 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				copy_ice[i][j] = ice[i][j];
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (ice[i][j] > 0) {
					melt(i, j);
				}
			}
		}
		answer++;
	}


	return 0;
}
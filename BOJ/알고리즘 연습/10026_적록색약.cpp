#include<iostream>
#include<cstdlib>
using namespace std;

int n;
int visited[101][101];
char color[101][101];
int cnt = 0;

int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int y,int x,char c ) {

	visited[y][x] = 1;

	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i];
		int X = x + dx[i];

		if (0 <= Y && Y < n && 0 <= X && X < n) {
			if (color[Y][X] == c && visited[Y][X] == 0)
				dfs(Y, X, c);
		}
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> color[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && color[i][j] == 'R') {
				dfs(i, j, 'R');
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && color[i][j] == 'B') {
				dfs(i, j, 'B');
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && color[i][j] == 'G') {
				dfs(i, j, 'G');
				cnt++;
			}
		}
	}

	cout << cnt << " ";

	memset(visited, 0, sizeof(visited));
	cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (color[i][j] == 'R') color[i][j] = 'G';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && color[i][j] == 'B') {
				dfs(i, j, 'B');
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0 && color[i][j] == 'G') {
				dfs(i, j, 'G');
				cnt++;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}
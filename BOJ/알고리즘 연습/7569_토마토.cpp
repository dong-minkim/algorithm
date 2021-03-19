#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int arr[101][101][101];
queue<pair<int,pair<int, int>>> tomato;
int m, n, h;
int dx[6] = {0,0,1,0,0,-1 };
int dy[6] = {1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,1,-1,0 };

void bfs() {
	while (!tomato.empty()) {
		int x = tomato.front().second.second;// j
		int y = tomato.front().second.first; // i
		int z = tomato.front().first; // k
		tomato.pop();
		for (int i = 0; i < 6; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];
			int Z = z + dz[i];
			if (0<=Z && Z<h && 0 <= X && X < m && 0 <= Y && Y < n && arr[Z][Y][X] == 0) {
				arr[Z][Y][X] = arr[z][y][x] + 1;
				tomato.push(make_pair(Z,make_pair(Y, X)));
			}
		}

	}
}

int main()
{

	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[k][i][j];
				if (arr[k][i][j] == 1) tomato.push(make_pair(k,make_pair(i, j)));
			}
		}
	}


	bfs();

	int max = 0;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[k][i][j] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				if (max < arr[k][i][j]) max = arr[k][i][j];
			}
		}
	}
	cout << max - 1 << '\n';

	return 0;
}
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
vector<vector<int>> arr(1001);
queue<pair<int, int>> tomato;
int m, n;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void bfs() {
	while (!tomato.empty()) {
		int x = tomato.front().second;// j
		int y = tomato.front().first; // i
		tomato.pop();
		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];

			if (0 <= X && X < m && 0 <= Y && Y < n && arr[Y][X] == 0) {
				arr[Y][X] = arr[y][x] + 1;
				tomato.push(make_pair(Y, X));
			}
		}

	}
}

int main()
{

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int num;
			cin >> num;
			arr[i].push_back(num);
			if (num == 1) tomato.push(make_pair(i, j));
		}
	}


	bfs();

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (max < arr[i][j]) max = arr[i][j];
		}
	}
	cout << max - 1 << '\n';

	return 0;
}
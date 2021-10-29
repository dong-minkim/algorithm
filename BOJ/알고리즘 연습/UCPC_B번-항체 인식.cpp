#include<iostream>
#include<queue>

using namespace std;

int n, m;
int map[31][31];
int result[31][31];
bool flag = false;
int tmp_result;
int tmp_map;
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
queue<pair<int, int>> qortls;

void bfs() {
	while (!qortls.empty()) {
		int y = qortls.front().first;
		int x = qortls.front().second;
		map[y][x] = tmp_result;
		qortls.pop();
		for (int i = 0; i < 4; i++) {
			int Y = y + dy[i];
			int X = x + dx[i];

			//tmp_2 는 백신맞는 map의 값
			if (0 <= X && X < m && 0 <= Y && Y < n && map[Y][X] == tmp_map) {
				map[Y][X] = tmp_result;
				qortls.push({ Y,X });
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> result[i][j];
			if (flag == false && map[i][j] != result[i][j]) {
				flag = true;
				qortls.push({ i, j });
				tmp_result = result[i][j];
				tmp_map = map[i][j];
				map[i][j] = result[i][j];
			}
		}
	}


	bfs();


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != result[i][j]) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	cout << "YES" << '\n';
	return 0;

}
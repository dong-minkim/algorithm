#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int m;
string arr[100];
bool visited[100][100] = { false, };
int check[100][100] = { 0, };
int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };

void bfs(int a,int b) {
	visited[a][b] = true;
	queue<pair<int, int>>q;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int X = x + dx[i];
			int Y = y + dy[i];
			if (0 <= X && X < m && 0 <= Y && Y < n && arr[Y][X] == '1' && !visited[Y][X]) {
				check[Y][X] = check[y][x] + 1;
				visited[Y][X] = true;
				q.push(make_pair(Y, X));
			}
		}
	}
	
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	bfs(0, 0);

	cout << check[n - 1][m - 1] + 1;

	return 0;
}
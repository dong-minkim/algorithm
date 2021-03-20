#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m;
char arr[51][51];
queue<pair<int, int>> q;
int sum[51][51];


int main() {
	cin >> n >> m;
	//vÀÔ·Â
	for (int g = 0; g < n; g++) {
		for (int h = 0; h < m; h++) {
			cin >> arr[g][h];
		}
	}
	//
	int max_ = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'W') continue;
			q.push(make_pair(i, j));
			memset(sum, 0, sizeof(sum));
			while (!q.empty()) {
				int y = q.front().first;
				int x = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int yy = y + dy[k];
					int xx = x + dx[k];

					if (yy < 0 || xx < 0 || yy >= n || xx >= m || arr[yy][xx] == 'W' || (yy == i && xx == j)) continue;
					if (!sum[yy][xx] || (sum[yy][xx] > sum[y][x] + 1)) {
						sum[yy][xx] = sum[y][x] + 1;
						q.push(make_pair(yy, xx));
					}

				}
			}
			for (int c = 0; c < n; c++) {
				for (int d = 0; d < m; d++) {
					if (sum[c][d]) max_ = max(max_, sum[c][d]);
				}
			}
		}
	}
		cout << max_;
		return 0;
}
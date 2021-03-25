#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int t;
int n, m, k;
int arr[51][51] = { 0, };
int check[51][51] = { 0, };
int dx[4] = { 0, 0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0;

void dfs(int a,int b) {
	check[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		int yy = a + dy[i];
		int xx = b + dx[i];
		if (arr[yy][xx] == 1) {
			if (check[yy][xx] == 0) {
				check[yy][xx] = 1;
				dfs(yy, xx);
			}
		}
	}
}
int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		while (k--) {
			int a, b;
			cin >> a >> b;
			arr[a][b]++;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1 && check[i][j] == 0) {
					dfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
		memset(arr, 0, sizeof(arr));
		memset(check, 0, sizeof(check));
		cnt = 0;
	}
	return 0;
}
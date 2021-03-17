#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
int arr[25][25];
bool visited[25][25];
int cnt;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
vector<int> v;

void dfs(int a, int b) {
	cnt++;
	visited[a][b] = true;
	for (int i = 0; i < 4; i++) {
		int X = a + dx[i];
		int Y = b + dy[i];
		if(X < 0 || X>= n || Y < 0 || Y >= n) continue;
		if (arr[X][Y] == 1 && visited[X][Y] == false) {
			dfs(X, Y);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		for (int j = 0; j < n; j++) arr[i][j] = st[j] - '0';
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == false) {
				cnt = 0;
				dfs(i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';

	return 0;
}
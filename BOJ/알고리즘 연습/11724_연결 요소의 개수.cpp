#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool visited[1001];
vector<int> arr[1001];

void dfs(int num) {
	//정점 방문
	visited[num] = true;
	for (int i = 0; i < arr[num].size(); i++) {
		int next = arr[num][i];
		if (!visited[next]) dfs(next);
	}
}

int main()
{
	int n, m;
	int x, y;
	int cnt = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	for (int i = 1; i < n; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}

	cout << cnt << '\n';

	return 0;
}

#include<iostream>
#include<queue>
using namespace std;

int arr[1001][1001];
int visit[1001];

void dfs(int v, int N) {
	cout << v << ' ';
	visit[v] = 1;
	for (int i = 1; i <= N; i++) {
		if (visit[i] == 1 || arr[v][i] == 0) continue;
		dfs(i, N);
	}
}
void bfs(int v, int N) {
	queue<int> q;
	q.push(v);
	visit[v] = 0;

	while (!q.empty()) {
		v = q.front();
		cout << v << ' ';
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (arr[v][i] == 0 || visit[i] == 0) continue;
			q.push(i);
			visit[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M, V;
	cin >> N >> M >> V;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		arr[x][y] = arr[y][x] = 1;
	}
	dfs(V, N);
	cout << '\n';
	bfs(V, N);


	return 0;
}
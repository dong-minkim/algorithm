#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int n, m;
vector<pair<long long, long long>> map[100001];
bool visited[100001] = { false, };
int start;
int arrive;

int bfs(int cost) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now == arrive) return 1;

		for (int i = 0; i < map[now].size(); i++) {
			long long next = map[now][i].first;
			long long next_cost = map[now][i].second;
			
			if (visited[next] == false && cost <= next_cost) {
				q.push(next);
			}
		}
	}
	return 0;
}

int main()
{
	cin >> n >> m;
	int tmp = 0;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		map[a].push_back({ b,c });
		map[b].push_back({ a,c });
		tmp = max(tmp, c);
	}

	
	cin >> start >> arrive;

	int left = 0, right=tmp;

	while (left <= right) {

		fill(visited, visited + n + 1, false);

		int mid = (left + right) / 2;
		if (bfs(mid)) left = mid + 1;
		else right = mid - 1;
	}
	cout << right << '\n';

	return 0;
}
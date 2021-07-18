#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n, m;
int a, b, c;
int dist[1002];
vector<pair<int, int>> v[1002];
priority_queue<pair<int,int>> pq;
int answer[1002];

int main()
{
	cin >> n >> m;
	//input
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	//
	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}

	//
	dist[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int now = pq.top().second;
		int now_cost = -pq.top().first;
		pq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int next_cost = v[now][i].second;

			if (dist[next] > now_cost + next_cost) {
				dist[next] = now_cost + next_cost;
				pq.push({ -dist[next],next });
				answer[next] = now;
			}
		}
	}

	cout << n - 1 << '\n';
	for (int i = 2; i <= n; i++) {
		cout << answer[i] << " " << i << '\n';
	}

	return 0;
}
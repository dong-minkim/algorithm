#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m, x;
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>>pq;
int dist[1001];
int answer[1001];
int result=0;

void sol(int start) {
	
	memset(dist, 1e6, sizeof(dist));
	
	

	dist[start] = 0;
	pq.push({ 0,start });

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
			}

		}
	}

}

int main()
{
	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}

	//x번에서 출발
	sol(x);

	

	for (int i = 1; i <= n; i++) {
		answer[i] = dist[i];
	}

	//x번 도착
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		sol(i);
		answer[i] += dist[x];
		result = max(result, answer[i]);
	}

	cout << result << '\n';

	return 0;
}
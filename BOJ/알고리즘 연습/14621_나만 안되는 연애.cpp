#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

priority_queue<pair<int, int>>pq;
vector<pair<int, int>> V[1001];
int n, m;
int u, v, d;
bool visited[1001] = { false, };
vector<char> sex;
char pre_sex = 'A';
int answer = 0;


void solution(int start) {
	pq.push({ 0,start });
	while (!pq.empty()) {
		int now = pq.top().second;
		int min_edge = -pq.top().first;
		pq.pop();
		if (visited[now])continue;
		visited[now] = true;
		answer += min_edge;
		for (int i = 0; i < V[now].size(); i++) {
			int next = V[now][i].first;
			int next_edge = V[now][i].second;
			if (visited[next] || sex[now]==sex[next]) continue;
			pq.push({ -next_edge,next });
		}
	}
}

int main()
{
	cin >> n >> m;
	sex.push_back('S');
	for (int i = 0; i < n; i++) {
		char gender;
		cin >> gender;
		sex.push_back(gender);
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> d;
		V[u].push_back({ v,d });
		V[v].push_back({ u,d });
	}

	solution(1);
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			cout << -1 << '\n';
			return 0;
		}
	}
	cout << answer << '\n';

	return 0;
}
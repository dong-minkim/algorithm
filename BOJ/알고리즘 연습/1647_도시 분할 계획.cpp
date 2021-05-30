#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;

int N, M;
int a, b, c;
vector<int> parent;
vector<pair<int,int>> edge[100001];
int gp_size[100001];
priority_queue<pair<int, int>> pq;
bool visited[100001] = { false, };
int answer = 0;
int max_edge = 0;
int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (gp_size[a] < gp_size[b]) swap(a, b); //merge ÃÖÀûÈ­
	gp_size[a] += gp_size[b];
	parent[b] = a;
}

void solution(int start) {
	pq.push({ 0,start});
	while (!pq.empty()) {
		int now = pq.top().second;
		int min_edge = -pq.top().first;
		pq.pop();
		if (visited[now]) continue;
		visited[now] = true;
		answer += min_edge;
		max_edge = max(max_edge, min_edge);
		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i].first;
			int next_edge = edge[now][i].second;
			if (visited[next]) continue;
			pq.push({ -next_edge,next });

		}
	}
}

int main()
{
	cin >> N >> M;
	parent.push_back(0);
	memset(gp_size, 1, sizeof(gp_size));

	for (int i = 1; i <= N; i++) {
		parent.push_back(i);
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}

	solution(1);

	cout << answer-max_edge<<'\n';

	return 0;
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int V, E;
int A, B, C;

vector<pair<int, int>> edge[10001];
priority_queue<pair<int, int>> pq;
bool visited[10001] = { false, };
int answer = 0;

void Prim(int start) {
	pq.push({ 0,start });
	while (!pq.empty()) {
		int now = pq.top().second; //현재 정점
		int min_edge = -pq.top().first; //가장 짧은 간선
		pq.pop();

		if (visited[now])continue; //방문했으면 패스

		visited[now] = true; //정점에 마크
		answer += min_edge; //선택된 짧은 간선을 더해준다.

		for (int i = 0; i < edge[now].size(); i++) { //현재 정점과 연결돼 있는 정점 넣는다.
			if (visited[edge[now][i].first]) continue;
			pq.push({ -edge[now][i].second , edge[now][i].first});
		}
	}
}

int main()
{
	cin >> V >> E;
	
	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		edge[A].push_back({ B,C });
		edge[B].push_back({ A,C });
	}

	Prim(1);
	cout << answer << '\n';
	return 0;
}
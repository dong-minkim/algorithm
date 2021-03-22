#include<iostream>
#include<vector>
#include<queue> // 우선순위 큐 사용하기 위함

using namespace std;

int V, E;
int K;
int u, v, w;
int s, de;
priority_queue<pair<int, int>> pq;
vector<pair<int,int>> e[100001]; //간선 정보
int d[1001];//최단거리

void dijkstra(int node) {
	
	
	d[node] = 0; //시작하는 노드는 최단거리 0
	pq.push(make_pair(0, node));

	while (!pq.empty()) {
		int distance=-pq.top().first;
		int current=pq.top().second;//pq.top().second는 음수이다 (top에서 가장 최단거리를 뽑기위해)
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < e[current].size(); i++) {
			int next = e[current][i].first;
			int next_distance = distance + e[current][i].second;
			if (next_distance < d[next]) {
				d[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}
		}
	}
}
int main()
{
	cin >> V >> E;
	
	for (int i = 1; i <= V; i++) {
		d[i] = 1e9;
	}
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		e[u].push_back(make_pair(v, w)); //u에서 v 정점 가중치는 w
	}
	cin >> s >> de;
	dijkstra(s);
	cout << d[de];

	return 0;
}
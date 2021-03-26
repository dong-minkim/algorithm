#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<queue> // 우선순위 큐 사용하기 위함

using namespace std;

int T;
int n,d;
int c;
int a,b,s;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> e[100001]; //간선 정보
int time[10001] = { 0, };//최단거리
vector<int> arr;

void dijkstra(int node) {


	time[node] = 0; //시작하는 노드는 최단거리 0
	pq.push(make_pair(0, node));

	while (!pq.empty()) {
		int distance = -pq.top().first;
		int current = pq.top().second;//pq.top().second는 음수이다 (top에서 가장 최단거리를 뽑기위해)
		pq.pop();
		if (time[current] < distance) continue;
		for (int i = 0; i < e[current].size(); i++) {
			int next = e[current][i].first;
			int next_distance = distance + e[current][i].second;
			if (next_distance < time[next]) {
				time[next] = next_distance;
				pq.push(make_pair(-next_distance, next));
			}
		}
	}
}


int main()
{
	int result_1 = 0, result_2 = 0;
	cin >> T;
	while(T--){
		cin >> n >> d >> c;
		

		for (int i = 1; i <= n; i++) {
			time[i] = 10000000;
		}
		for (int i = 0; i < d; i++) {
			cin >> a >> b >> s;
			e[b].push_back(make_pair(a, s)); //u에서 v 정점 가중치는 w
		}

		dijkstra(c);

		result_1 = 0;
		result_2 = 0;
		for (int i = 1; i <=n; i++) {
			if (time[i] != 10000000) {
				result_1++;
				if (result_2 < time[i]) result_2 = time[i];
			}
		}
		
		cout << result_1 << ' ' << result_2<<'\n';
		
		memset(time, 0, sizeof(time));
		memset(e, 0, sizeof(e));
	}
	



	return 0;
}
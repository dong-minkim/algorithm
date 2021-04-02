#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

long long D, P, C, F, S;
long long J, K, T;
vector<pair<long long, long long>> edge[221];
long long dist[221];
bool cycle;
long long cost;

int main()
{
	cin >> D >> P >> C >> F >> S;
	//D:벌수 있는 금액
	//P:간선(도로)
	//C:정점(도시)
	//F:제트기 개수
	//S:출발 지점
	cost = -D;
	for (int i = 1; i <= C; i++) {
		dist[i] = 1e15;
	}
	
	for (int i = 0; i < P; i++) {
		cin >> J >> K;
		edge[J].push_back(make_pair(K, -D));
	}
	for (int i = 0; i < F; i++) {
		cin >> J >> K >> T;
		edge[J].push_back(make_pair(K, -D+T));
	}
	dist[S] = -D;
	cycle = false;
	for (int i = 1; i <= C+1; i++) {
		for (int j = 1; j <= C; j++) {
			for (int k = 0; k< edge[j].size(); k++) {
				long long next = edge[j][k].first;
				long long distance = edge[j][k].second;
				if (dist[j] == 1e15) continue;
				if (dist[next] > distance + dist[j]) {
					dist[next] = distance + dist[j];
					cost = min(cost, dist[next]);
					if (i==C+1) {
						cycle = true;
					}
				}
			}
		}
	}


	if (cycle) cout << -1 << '\n';
	else cout << -cost << '\n';
	

	return 0;
}
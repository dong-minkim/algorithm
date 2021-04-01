#include<iostream>
#include<vector>

using namespace std;
int N,M;
int A, B, C;
vector<pair<int, int>> edge[6001];
long long dist[501];
bool cycle = false;

void Bellman() {
	dist[1] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < edge[j].size(); k++) {
				int next = edge[j][k].first;
				int distance = edge[j][k].second;
				if (dist[next] > dist[j] + distance) {
					dist[next] = dist[j] + distance;
					if (i == N) { cycle = true; }
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		edge[A].push_back(make_pair(B, C));
	}
	for (int i = 1; i <= N; i++) {
		dist[i] = 1e15;
	}
	Bellman();
	if (cycle == true) cout << -1 << '\n';
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == 1e15) cout << -1 << '\n';
			else cout << dist[i] << '\n';
		}
	}

	return 0;
}
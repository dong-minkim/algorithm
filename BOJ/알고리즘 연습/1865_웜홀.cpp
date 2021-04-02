#include<iostream>
#include<vector>

using namespace std;

int n, m, w;
int s, e, t;
long long dist[101];
vector< pair<int, int>> edge[2501];
bool cycle;

void Bellman() {
	cycle = false;
	dist[1] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < edge[j].size(); k++) {
				int next = edge[j][k].first;
				int distance = edge[j][k].second;
				if (dist[next] > dist[j] + distance) {
					dist[next] = dist[j] + distance;
					if (i == n) cycle = true;
				}
			}
		}
	}
}

int main() {

	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n >> m >> w;
		
		for (int i = 1; i <= n; i++) {
			edge[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			dist[i] = 1e9;
		}

		for (int i = 0; i < m; i++) {
			cin >> s >> e >> t;
			edge[s].push_back(make_pair(e, t));
			edge[e].push_back(make_pair(s, t));
		}
		
		for (int i = 0; i < w; i++) {
			cin >> s >> e >> t;
			edge[s].push_back(make_pair(e, -t));
		}
		
		Bellman();
		
		if (cycle) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	
	}

	return 0;
}
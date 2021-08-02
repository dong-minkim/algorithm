#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

priority_queue<pair<int, pair<int, int>>> pq;
int parent[100001];

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

int main() {

	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
	}

	int a, b;
	cin >> a >> b;

	while (!pq.empty()) {
		int x = find(pq.top().second.first);
		int y = find(pq.top().second.second);
		int dist = pq.top().first;
		pq.pop();

		parent[y] = x;

		if (find(b) == find(a)) {
			cout << dist << '\n';
			return 0;
		}
	}
	

	return 0;
}
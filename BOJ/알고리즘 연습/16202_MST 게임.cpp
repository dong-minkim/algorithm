#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n, m, k;
vector<pair<int, int>> edge;
priority_queue < pair<int, pair<int, int>>>pq;
bool flag;
int parent[1001];
int sum = 0;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edge.push_back({ a,b });
	}

	for (int i = 0; i < k; i++) {
		if (m - i < n - 1) {
			cout << 0 << ' ';
			continue;
		}

		for (int j = 1; j <= n; j++) parent[j]=j;

		for (int j = i; j < m; j++) {
			pq.push({ -(j + 1),{edge[j].first,edge[j].second} });
		}

		int tmp = 0;
		sum = 0;
		for (int j = i; j < m; j++) {
			int dist = -pq.top().first;
			int start = pq.top().second.first;
			int dest = pq.top().second.second;
			pq.pop();

			if (find(start) == find(dest)) continue;
			tmp++;
			merge(find(start), find(dest));
			sum += dist;
		}
		
		if (tmp == n - 1) cout << sum << " ";
		else cout << 0 << " ";

	}

	return 0;
}
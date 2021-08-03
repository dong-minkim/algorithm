#include<iostream>
#include<queue>

using namespace std;

int m, n;
priority_queue<pair<int, pair<int, int>>> pq;
int parent[200001];

int find(int x) {
	if (parent[x] == x)return x;
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
	cin >> n >> m;

	while (m != 0 && n != 0) {
		int sum = 0;
		//input
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			sum += z;
			pq.push({ -z,{x,y} });
		}

		for (int i = 0; i < m; i++) {
			parent[i] = i;
		}

		int sum2 = 0;
		while (!pq.empty()) {
			int a = find(pq.top().second.first);
			int b = find(pq.top().second.second);
			int dist = -pq.top().first;
			pq.pop();
			if (a == b) continue;
			merge(a, b);
			sum2 += dist;
		}

		cout << sum - sum2<<'\n';

		cin >> n >> m;
	}


	return 0;
}
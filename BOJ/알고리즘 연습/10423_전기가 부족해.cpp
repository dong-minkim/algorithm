#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int parent[1001];
int visited[1001];
int gp_size[1001];
vector<int> baljun;
priority_queue<pair<int, pair<int, int>>> pq;
int n, m, k;
int u, v, w;

int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}
void merge(int a,int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (gp_size[a] < gp_size[b])swap(a, b);
	gp_size[a] += gp_size[b];
	parent[b] = a;
}

int main()
{
	cin >> n >> m >> k;
	
	for (int i = 1; i <= n; i++) parent[i] = i;

	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		baljun.push_back(num);
	}

	for (int i = 0; i < k - 1; i++) {
		merge(baljun[i], baljun[i + 1]);
	}

	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		pq.push({ -w,{u,v} });
	}
	int answer = 0;
	while (!pq.empty()) {
		int a = find(pq.top().second.first);
		int b = find(pq.top().second.second);
		int weight = -pq.top().first;
		pq.pop();
		if (a == b) continue;//루트노드가 같다면 같은 집합 => 사이클
		merge(a, b);//다르다면 합친다.
		answer += weight;
	}

	cout << answer << '\n';

	return 0;
}
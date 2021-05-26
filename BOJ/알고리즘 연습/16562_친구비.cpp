#include<iostream>
#include<algorithm>
using namespace std;

int n, m, k;
int sum = 0;
int x, y;
int parent[10002];
int cost[10002];
bool visited[10002] = { false, };

int find(int n) {
	if (parent[n] == n) return n;
	else return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (cost[a] > cost[b]) swap(a, b);
		parent[b] = a;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		cin >> cost[i];
	}
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		if (find(x) != find(y)) merge(x, y);
	}

	for (int i = 1; i <= n; i++) {
		int root = find(i);
		if (visited[root] == false) {
			k -= cost[root];
			if (k < 0) {
				cout << "Oh no";
				return 0;
			}
			visited[root] = true;
			sum += cost[root];
		}
	}
	cout << sum << '\n';


	return 0;
}
#include<iostream>
#include<vector>

using namespace std;

int T; int N;
int a, b, c;
vector<pair<int, int>> v;
vector<int> radius;
int parent[3001];

int dist(int r1, int r2) {
	int r = (r1 + r2) * (r1 + r2);
	return r;
}
int point_dist(int x1, int y1, int x2, int y2) {
	int x = (x1 - x2) * (x1 - x2);
	int y = (y1 - y2) * (y1 - y2);
	return x + y;
}
int find(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	int x = find(a);
	int y = find(b);
	if (x != y) parent[x] = y;
}

int main()
{
	cin >> T;
	for (int i = 0; i < T; i++) {

		cin >> N;
		int cnt = N;
		
		for (int j = 0; j < N; j++) {
			parent[j] = j;
			cin >> a >> b >> c;
			v.push_back({ a,b });
			radius.push_back(c);
		}

		for (int p = 0; p < N-1; p++) {
			for (int q = p + 1; q < N; q++) {
				if (find(p) == find(q)) continue;
				if (dist(radius[p], radius[q]) >= point_dist(v[p].first, v[p].second, v[q].first, v[q].second)) {
					merge(p, q);
					cnt--;
				}
			}
		}
		v.clear();
		radius.clear();
		cout << cnt << '\n';
	}


	return 0;
}
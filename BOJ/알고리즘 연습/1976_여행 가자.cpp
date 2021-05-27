#include<iostream>
#include<vector>

using namespace std;

vector<int> parent;

int find(int n) { //맨 위 루트노드
	if (parent[n] == n)return n;
	return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
}

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i <= N; i++) {
		parent.push_back(i);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1) merge(i, j);
		}
	}

	int start;
	cin >> start;
	start = find(start);
	for (int i = 0; i < M - 1; i++) {
		int num;
		cin >> num;
		if (start != find(num)) {
			cout << "NO" << '\n';
				return 0;
		}
	}
	cout << "YES" << '\n';

	return 0;
}
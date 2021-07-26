#include<iostream>
#include<vector>

using namespace std;

int parent[100002];
bool visited[100002];

vector<int> tree[100002];

void find(int start) {
	visited[start] = true;

	for (int i = 0; i < tree[start].size(); i++) {
		int next = tree[start][i];

		if (visited[next] == false) {
			parent[next] = start;
			find(next);
		}
	}
}

int main()
{
	int n;
	cin >> n;

	//tree ют╥б
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	find(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}
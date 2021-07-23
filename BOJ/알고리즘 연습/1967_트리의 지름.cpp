#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<pair<int, int>> edge[10002];
bool visited[10002] = { false, };
int answer = 0;
int tmp_node;

void solution(int start, int radius) {
	
	visited[start] = true;
	//cout << start << '\n';

	if (answer < radius) {
		answer = radius;

		tmp_node = start;
	}


	for (int i = 0; i < edge[start].size(); i++) {
		if (visited[edge[start][i].first] == true) continue;
		solution(edge[start][i].first, edge[start][i].second + radius );
	}

}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}


	solution(1, 0); // 노드1에서 시작하고 이때 거리 0

	//cout << tmp_node << '\n';
	//cout << answer << '\n';

	fill(visited, visited + n + 1, false);

	answer = 0;
	solution(tmp_node, 0);

	
	
	cout << answer << '\n';

	return 0;
}
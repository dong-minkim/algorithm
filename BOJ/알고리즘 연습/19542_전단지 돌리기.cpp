#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> node[100001];
bool visited[100001];
int node_distance[100001] = { 0, };
int answer = 0;
int n, s, d;

int dfs(int start, int level) {

	int dist = level;

	for (int i = 0; i < node[start].size(); i++) {
		int next = node[start][i];
		if (visited[next] == false) {
			visited[next] = true;
			dist = max(dist, dfs(next, level + 1));
		}
	}
	node_distance[start] = dist - level;
	
	return dist;

}

void solution(int start, int distance) {
	for (int i = 0; i < node[start].size(); i++) {
		int next = node[start][i];
		if (visited[next] == false && node_distance[next] >= distance) {
			visited[next] = true;
			answer++;

			cout << answer << " " << next << '\n';
			solution(next, distance);
		}
	}
}

int main()
{
	int n, s;

	cin >> n >> s >> d;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	visited[s] = true;

	dfs(s, 0);
	fill(visited, visited + n + 1, false);
	
	visited[s] = true;
	solution(s, d);


	cout << answer*2 << '\n';

	return 0;
}
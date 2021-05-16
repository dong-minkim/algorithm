#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
vector<int> v[1001];
queue<int> q;
int in_degree[1001];
vector<int> answer;
int visited[1001][1001] = { 0, };


int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		num -= 1;
		int order;
		int order2;
		cin >> order;
		while (num--) {
			cin >> order2;
			if (visited[order][order2] == 1) continue;
			else {
				visited[1001][1001] = 1;
				v[order].push_back(order2);
				in_degree[order2]++;
			}
			order = order2;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int now = q.front();
		answer.push_back(now);
		q.pop();
		for (int i = 0; i < v[now].size();i++) {
			int next = v[now][i];
			in_degree[next]--;
			if (in_degree[next] == 0) q.push(next);
		}
	}

	if (answer.size() != N) cout << '0' << '\n';
	else {
		for (int i = 0; i < N; i++) {
			cout << answer[i] << '\n';
		}
	}

	return 0;
}
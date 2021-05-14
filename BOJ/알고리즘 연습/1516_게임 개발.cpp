#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> v[501];
queue<int> q;
int in_degree[501];
int dp[501];

int main() {

	int N;
	cin >> N;
	int time[501] = { 0, };

	for (int i = 1; i <= N; i++) {
		
		cin >> time[i];
		dp[i] = time[i];
		
		while (1) {
			int num;
			cin >> num;
			if (num == -1) break;
			v[num].push_back(i);
			in_degree[i]++;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		
		int now = q.front();
		q.pop();

		for (int i = 0; i < v[now].size(); i++) {
			
			int next = v[now][i];
			dp[next] = max(dp[next], time[next] + dp[now]);

			in_degree[next]--;
			if (in_degree[next] == 0) {
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << dp[i] << '\n';
	}
	

	return 0;
}
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

long long indegree[1001];
long long cnt[101][101];
vector<vector<pair<long long,long long>>> edge;
queue<long long> q;



int main()
{
	long long n, m;
	cin >> n >> m;

	edge.resize(n + 1);

	for (long long i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		edge[b].push_back({ a,c }); // a를 만드는데 b가 c개 필요하다.
		indegree[a]++;
	}

	for (long long i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			cnt[i][i] = 1;
		}
	}

	//cnt[a][b]  =>  a제품을 만드는데 필요한 b부품의 개수

	while (!q.empty()) {
		long long now;
		now = q.front();
		q.pop();

		for (long long i = 0; i < edge[now].size(); i++) {
			for (long long j = 1; j <= n; j++) {
			//  한 제품을 만드는 데 +=  (now부속품을 만드는데 필요 개수) * 몇개필요한가
				cnt[edge[now][i].first][j] += cnt[now][j] * edge[now][i].second;
			}

			indegree[edge[now][i].first]--;

			if (indegree[edge[now][i].first] == 0) q.push(edge[now][i].first);
		}
	}


	for (long long i = 1; i <= n; i++) {
		if (cnt[n][i] != 0) cout << i << " " << cnt[n][i] << '\n';
	}

	return 0;
}
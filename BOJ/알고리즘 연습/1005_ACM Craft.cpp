#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;

int Time[1005];
vector<int> v[1005];
int len[1005];
queue<int> q;
int dp[1005];

int a, b;

int main()
{
	int T;
	int N, K;
	int dest;


	cin >> T;
	while (T--) {
		cin >> N >> K;


		//¸®¼Â
		memset(Time, 0, sizeof(Time));
		memset(len, 0, sizeof(len));
		memset(dp, 0, sizeof(dp));
		while (q.size()) q.pop();
		for (int i = 0; i < 1005; i++) {
			v[i].clear();
		}

		for (int i = 1; i <= N; i++) {
			cin >> Time[i];
			dp[i] = Time[i];
		}

		for (int i = 0; i < K; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			len[b]++;
		}

		cin >> dest;



		for (int i = 1; i <= N; i++) {
			if (len[i] == 0) q.push(i);
		}

		int next=0;

		while (len[dest]) {
			int now = q.front();
			q.pop();
			
			for (int i = 0; i < v[now].size(); i++) {
				 next = v[now][i];
				len[next]--;
				if (len[next] == 0) q.push(next);
				dp[next] = max(dp[next], dp[now] + Time[next]);
			}
		}
		
		cout <<dp[dest] << '\n';

	}

	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int N;
int dp[1000001];
int x;
int Answer;

int main() {
	FAST_IO;

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> x;
		dp[x] = dp[x - 1] + 1;
		Answer = max(Answer, dp[x]);
	}
	cout << N - Answer;

	return 0;
}
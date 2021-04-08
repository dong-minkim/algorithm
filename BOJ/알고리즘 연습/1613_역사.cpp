#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int history[401][401] = { 0, };

int main()
{
	int n, k;
	int a, b;
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a >> b;
		history[a][b] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=n ; j++) {
			for (int h = 1; h <= n; h++) {
				if (history[j][i] && history[i][h]) history[j][h] = 1;
			}
		}
	}
	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		cin >> a >> b;
		if (history[a][b] == 1)cout << -1 << '\n';
		else if (history[b][a] == 1) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}
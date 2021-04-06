#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int item[101] = { 0, };
int arr[101][101];
int main()
{
	int n, m, r;
	int t;
	int a, b, l;
	int answer=0;

	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		cin >> item[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) arr[i][j] = 1e9;
		}
	}
	for (int i = 0; i < r; i++) {
		cin >> a >> b >> l;
		arr[a-1][b-1] = arr[b-1][a-1] = l;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k])
					arr[j][k] = arr[j][i] + arr[i][k];
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt = item[i];
		for (int j = 0; j < n; j++) {
			if (i!=j && arr[i][j] <= m) cnt += item[j];
		}
		answer = max(answer, cnt);
	}

	cout << answer << '\n';

	return 0;
}
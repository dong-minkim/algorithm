#include<iostream>
#include<algorithm>
using namespace std;

int arr[201][201];
int answer[201][201];

int main()
{
	int n, m;
	cin >> n >> m;
	int a, b, c;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				answer[i][j] = j;
				arr[i][j] = 1e9;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		arr[a][b] = arr[b][a] =  c;
	}
	
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i!=j && arr[i][j] > arr[i][k] + arr[k][j]) {
					answer[i][j] = k;
					arr[i][j] = arr[i][k] + arr[k][j];
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || answer[i][j] == j) continue;
			int tmp = j;
			while (answer[i][tmp] != tmp) {
				tmp = answer[i][tmp];
			}
			answer[i][j] = tmp;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << answer[i][j]<<' ';
		}
		cout << '\n';
	}

	return 0;
}
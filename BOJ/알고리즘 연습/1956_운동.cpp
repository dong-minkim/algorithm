#include<iostream>
#include<algorithm>

using namespace std;
int arr[401][401] = { 0, };
int main()
{
	int V, E;
	int a, b, c;
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			 arr[i][j] = 1e9;
		}
	}
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		arr[a][b] = c;
	}
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				if (arr[i][j] >= arr[i][k] + arr[k][j])
					arr[i][j] = arr[i][k] + arr[k][j];
			}
		}
	}
	int answer = 1e9;
	for (int i = 1; i <= V; i++) {
		if (answer > arr[i][i]) answer = arr[i][i];
	}

	if (answer == 1e9) cout << -1 << '\n';
	else cout << answer << '\n';

	return 0;
}
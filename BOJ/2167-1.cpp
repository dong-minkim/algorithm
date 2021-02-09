#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[300][300];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int T;
	int i, j;
	int x, y;
	cin >> T;
	for (int k = 0; k < T; k++) {
		int sum = 0;
		cin >> i >> j;
		cin >> x >> y;
		for (int a = i - 1; a <= x - 1; a++) {
			for (int b = j - 1; b <= y - 1; b++) {
				sum += arr[a][b];
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
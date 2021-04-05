#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int arr[501][501] = { 0, };

int main()
{
	int n, m;
	int A, B, C;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 1; i <= n; i++) { //경유
		for (int j = 1; j <= n; j++) {//출발
			for (int k = 1; k <= n; k++) {//도착
				if (arr[j][k] > arr[j][i] + arr[i][k])
					arr[j][k] = arr[j][i] + arr[i][k];
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> A >> B >> C;
		if (arr[A][B] >= C) cout << "Enjoy other party" << '\n';
		else cout<<"Stay here"<<'\n';
	}


	return 0;
}
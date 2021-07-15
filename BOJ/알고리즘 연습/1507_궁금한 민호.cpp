#include<iostream>
#include<string.h>

using namespace std;

int n;
int flag[21][21] = { false, };
int dist[21][21];
int sum = 0;

void Input() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dist[i][j];
			sum += dist[i][j];
		}
	}

}


int main()
{
	cin >> n;

	Input();

	for (int k = 0; k < n; k++) { //°æÀ¯Áö
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i == j || j == k || k == i) continue;

				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					cout << -1 << '\n';
					return 0;
				}
				if (dist[i][j] == dist[i][k] + dist[k][j]) {
					flag[i][j] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (flag[i][j] == true) {
				sum -= dist[i][j];
			}
		}
	}

	cout << sum/2 << '\n';
	

	return 0;
}
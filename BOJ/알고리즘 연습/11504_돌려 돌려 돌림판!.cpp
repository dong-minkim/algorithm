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

char arr[101];

int main() {
	FAST_IO;
	int t;
	string x;
	string y;
	string z;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		x = "";
		y = "";
		for (int i = 0; i < m; i++) {
			char c;
			cin >> c;
			x += c;
		}
		for (int i = 0; i < m; i++) {
			char c;
			cin >> c;
			y += c;
		}
		int x_num = stoi(x);
		int y_num = stoi(y);

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		int Answer = 0;

		for (int i = 0; i < n; i++) {
			z = "";
			for (int j = 0; j < m; j++) {
				z += arr[(i + j)%n];
			}
			if (x_num <= stoi(z) && stoi(z) <= y_num) {
				Answer++;
			}
		}
		cout << Answer << '\n';
	}

	return 0;
}

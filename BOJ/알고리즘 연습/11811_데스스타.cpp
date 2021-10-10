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

int arr[1001];

int main() {
	FAST_IO;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			if (i == j) continue;
			arr[i] = arr[i] | num;
		}
	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
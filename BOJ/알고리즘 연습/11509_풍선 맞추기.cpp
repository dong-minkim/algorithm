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

int arr[1000001] = { 0, };

int main() {
	FAST_IO;

	int n;
	cin >> n;
	
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		int height;
		cin >> height;

		if (arr[height + 1] == 0) {
			cnt++, arr[height]++;
		}
		else {
			arr[height + 1]--, arr[height]++;
		}
	}

	cout << cnt << '\n';


	return 0;
}

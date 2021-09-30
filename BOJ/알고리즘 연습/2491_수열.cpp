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

int arr[100001] = { 0, };

int main() {
	FAST_IO;

	int n;
	int Answer = 1;
	int cnt = 1;
	int cnt2 = 1;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		if (arr[i] <= arr[i + 1]) {
			cnt++;
		}
		else cnt = 1;

		if (arr[i] >= arr[i + 1]) {
			cnt2++;
		}
		else cnt2 = 1;

		int tmp = max(cnt, cnt2);
		Answer = max(tmp, Answer);

	}

	cout << Answer << '\n';

	return 0;
}
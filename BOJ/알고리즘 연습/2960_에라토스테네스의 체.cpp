#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int cnt = 0;
	int arr[1001] = { 0, };

	for (int i = 2; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			if (arr[j] == 0) {
				arr[j] = 1;
				cnt++;
			}
			if (k == cnt) {
				cout << j << '\n';
				return 0;
			}
		}
	}

	return 0;
}
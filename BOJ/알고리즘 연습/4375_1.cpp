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

int main() {
	FAST_IO;
	int cnt;
	int n;
	while (cin >> n) {
		cnt = 1;
		long long num = 1L;
		while (1) {
			if (num % n == 0) {
				cout << cnt << '\n';
				break;
			}
			num = num * 10 + 1;
			cnt++;
		}
	}

	return 0;
}
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

long long x,k;
long long y;

int main() {
	FAST_IO;

	cin >> x >> k;
	long long tmp = 1;
	for (long long i = 1; k > 0; i = i << 1) {
		if (!(x & i)) {
			if (k & tmp) {
				y += i;
				k -= tmp;
			}
			tmp = tmp << 1;
		}
	}

	cout << y << '\n';

	return 0;
}
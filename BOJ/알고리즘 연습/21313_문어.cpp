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

	int n;
	cin >> n;
	
	int tmp = (n / 2) * 2;

	for (int i = 1; i <= tmp; i++) {
		if (i % 2 == 1) cout << 1 << " ";
		else cout << 2 << " ";
	}

	if (n % 2 == 1) cout << 3 << " ";


	return 0;
}

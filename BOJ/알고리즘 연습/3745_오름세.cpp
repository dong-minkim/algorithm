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

int n;
vector<int> arr;

int main() {
	FAST_IO;

	while (cin >> n) {
		arr.clear();
		for (int i = 1; i <= n; i++) {
			int cost;
			cin >> cost;
			if (arr.empty() || arr.back() < cost)arr.push_back(cost);
			else {
				int idx = lower_bound(arr.begin(), arr.end(), cost) - arr.begin();
				arr[idx] = cost;
			}
		}
		cout << arr.size() << '\n';
	}

	return 0;
}
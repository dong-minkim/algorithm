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
	priority_queue<int,vector<int>,greater<int>> pq;

	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		pq.push(number);
	}

	

	int sum = 0;
	while (1) {
		if (pq.size() == 1) {
			cout << sum << '\n';
			return 0;
		}
		else {
			int tmp = 0;
			tmp += pq.top(); pq.pop();
			tmp += pq.top(); pq.pop();
			sum += tmp;
			pq.push(tmp);
		}

	}

	return 0;
}
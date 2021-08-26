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

priority_queue<int, vector<int>, greater<int>>pq;
int n, m;

int main() {
	FAST_IO;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.push(num);
	}

	for (int i = 0; i < m; i++) {
		int num1 = pq.top();
		pq.pop();
		int num2 = pq.top();
		pq.pop();
		pq.push(num1 + num2);
		pq.push(num1 + num2);
	}

	int sum = 0;
	while(!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}

	cout << sum << '\n';

	return 0;
}
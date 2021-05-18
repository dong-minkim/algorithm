#include <iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int testcase;
	cin >> testcase;
	int x;

	for (int i = 0; i < testcase; i++) {
		cin >> x;
		if (x == 0 && !pq.empty()) {
			cout << pq.top() << '\n';
			pq.pop();
		}
		else if (x == 0 && pq.empty()) {
			cout << 0 << '\n';
		}
		else
		{
			pq.push(x);
		}
	}


	return 0;
}
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int N;
	cin >> N;

	int x;
	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) cout << 0 << '\n';
			else {
				cout << pq.top().second << '\n';
				pq.pop();
			}
		}
		else if (x != 0) {
			pq.push({ abs(x),x });
		}
	}

	return 0;
}
#include <iostream>
#include <queue>

using namespace std;

int main() {

	queue<int> q;
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
		q.push(i+1);
	cout << "<";
	while (q.size() > 1) {
		for (int i = 0; i < m; i++) {
			if ((i+1) != m) {
				int a = q.front();
				q.push(a);
				q.pop();
			}
			else {
				cout << q.front() << ", ";
				q.pop();
			}
		}
	}
	cout << q.front() << ">";
}
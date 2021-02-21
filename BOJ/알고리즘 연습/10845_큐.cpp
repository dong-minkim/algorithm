#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int> Q;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;

		string s;
		cin >> s;
		if (s == "push") {
			cin >> x;
			Q.push(x);
		}
		else if (s == "pop") {
			if (Q.empty()) cout << -1 << endl;
			else {
				cout << Q.front() << endl;
				Q.pop();
			}
		}
		else if (s == "size") {
			cout << Q.size() << endl;
		}
		else if (s == "empty") {
			if (Q.empty()) cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (s == "front") {
			if (Q.empty()) cout << -1 << endl;
			else cout << Q.front() << endl;
		}
		else if (s == "back") {
			if (Q.empty()) cout << -1 << endl;
			else cout << Q.back() << endl;
		}
	}
	return 0;
}
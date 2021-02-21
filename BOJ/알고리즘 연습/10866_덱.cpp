#include <iostream>
#include<deque>
using namespace std;

deque<int> d;
int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);

	int testcase;
	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		string s;
		cin >> s;
		int num;

		if (s == "push_front") {
			cin >> num;
			d.push_front(num);
		}
		else if (s == "push_back") {
			cin >> num;
			d.push_back(num);
		}
		else if (s == "front") {
			if (d.empty()) cout << -1 << '\n';
			else cout << d.front() << '\n';
		}
		else if (s == "back") {
			if (d.empty())cout << -1 << '\n';
			else cout << d.back() << '\n';
		}
		else if (s == "pop_front") {
			if (d.empty())cout << -1 << '\n';
			else {
				cout << d.front() << '\n';
				d.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (d.empty())cout << -1 << '\n';
			else {
				cout << d.back() << '\n';
				d.pop_back();
			}
		}
		else if (s == "size") {
			cout << d.size() << '\n';
		}
		else if (s == "empty") {
			if (d.empty()) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}

	return 0;
}
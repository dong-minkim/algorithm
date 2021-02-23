#include<iostream>
#include<algorithm>
#include<vector>
#include<deque>
#include<string>

using namespace std;

deque<char> q;

int main() {

	int testcase;
	cin >> testcase;
	while (testcase--) {
		int num;
		cin >> num;

		for (int i = 0; i < num; i++) {

			char c;
			cin >> c;
			if (q.empty()) q.push_back(c);
			else if (q.front() >= c) {
				q.push_front(c);
			}
			else q.push_back(c);
		}
		for (int i = 0; i < q.size(); i++) {
			cout << q[i];
		}
		cout << '\n';
		q.clear();
	}

	return 0;
}
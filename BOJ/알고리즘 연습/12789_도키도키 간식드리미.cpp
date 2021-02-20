#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main()
{
	int stu_num;
	cin >> stu_num;
	vector<int> v;
	queue<int> q;

	int cnt = 1;
	for (int i = 0; i < stu_num; i++) {
		int order;
		cin >> order;
		q.push(order);
	}
	while (!q.empty()) {
		if (q.front() == cnt) {
			q.pop();
			cnt++;
		}
		else if (!v.empty() && v.back() == cnt) {
			v.pop_back();
			cnt++;
		}
		else {
			v.push_back(q.front());
			q.pop();
		}
	}

	while (1) {
		if (v.empty()) break;
		int tmp = v.back();
		if (cnt != tmp) {
			cout << "Sad" << '\n';
			return 0;
		}
		else {
			v.pop_back();
			cnt++;
		}

	}
	cout << "Nice" << '\n';

	return 0;
}
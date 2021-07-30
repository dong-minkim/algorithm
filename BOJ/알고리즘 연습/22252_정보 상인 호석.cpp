#include<iostream>
#include<vector>
#include<queue>
#include<map>

using namespace std;

map<string, priority_queue<int>> m;

int main()
{
	int t;
	long long sum = 0;

	cin >> t;

	for (int i = 0; i < t; i++) {

		int key;
		string str;
		int num;

		cin >> key >> str >> num;

		if (key == 1) {
			for (int i = 0; i < num; i++) {
				int number;
				cin >> number;
				m[str].push(number);
			}
		}
		else {
			do {
				if (m[str].empty()) break;
				num--;
				sum += m[str].top();
				m[str].pop();
			} while (num!=0);
		}

	}

	cout << sum << '\n';

	return 0;
}
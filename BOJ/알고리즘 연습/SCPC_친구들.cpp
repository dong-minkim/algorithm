#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Answer;
vector<int> arr;
vector<int> parent;

int find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a < b) parent[b] = a;
	else parent[a] = b;
}


int main(int argc, char** argv)
{
	int T, test_case;
	int N;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		arr.clear();
		parent.clear();

		cin >> N;
		arr.push_back(0);
		for (int i = 0; i < N; i++) {
			int num;
			cin >> num;
			arr.push_back(num);
		}

		for (int i = 0; i <= N; i++) {
			parent.push_back(i);
		}

		for (int i = 1; i <= N; i++) {
			if (i + arr[i] <= N) {
				merge(i, i + arr[i]);
			}
		}

		for (int i = 1; i <= N; i++) {
			parent[i] = find(i);
		}

		sort(parent.begin(), parent.end());

		Answer = 0;
		int tmp = 0;
		for (int i = 1; i <= N; i++) {
			if (tmp != parent[i]) {
				Answer++;
				tmp = parent[i];
			}
		}

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;
}
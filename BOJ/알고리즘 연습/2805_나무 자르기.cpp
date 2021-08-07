#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m;
long long sum = 0;
vector<int> tree;

bool tmp(long long mid) {
	long long len = 0;

	for (int i = 0; i < n; i++) {
		if (tree[i] - mid > 0) len += tree[i] - mid;
	}

	if (len >= m) return true;
	else return false;
}

int main()
{
	cin >> n >> m;
	int longestTree = 0;;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		tree.push_back(num);
		longestTree = max(longestTree, num);
	}

	sort(tree.begin(), tree.end());

	int l = 0; int r = longestTree;

	long long result = 0;
	while (l <= r) {
		long long mid = (l + r) / 2;
		if (tmp(mid)) {
			result = max(result, mid);
			l = mid + 1;
		}
		else r = mid - 1;
	}

	cout << result << '\n';


	return 0;
}
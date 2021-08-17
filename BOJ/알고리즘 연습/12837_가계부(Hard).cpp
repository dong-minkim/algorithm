#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
long long n, k;
int h;

vector<long long> tree;

void update(int idx, long long val) {
	idx += h;
	tree[idx] += val;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
	}
}

long long query(int start, int end, int node, int left, int right) {
	if (left <= start && end <= right) return tree[node];
	if (end < left || right < start) return 0;

	int mid = (start + end) / 2;
	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
	FAST_IO;

	cin >> n >>  k;

	h = (int)ceil(log2(n));
	tree.resize(1 << (h + 1));
	h = 1 << h;

	for (int i = 0; i < k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c);
		}
		else {
			cout << query(1, h, 1, b, c) << '\n';
		}
	}
	return 0;
}
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

long long n, m;
int h;
vector<pair<long long, long long>>tree;
vector<long long> arr;

void update(int idx, int val) {
	idx += h;
	tree[idx] = { val,val };
	while (idx > 1) {
		idx /= 2;
		long long Min = min(tree[idx * 2].first, tree[idx * 2 + 1].first);
		long long Max = max(tree[idx * 2].second, tree[idx * 2 + 1].second);
		tree[idx] = { Min,Max };
	}
}

pair<long long, long long> query(int start, int end, int node, int left, int right) {

	if (left <= start && end <= right) return tree[node];
	if (end < left || right < start) return { 1e9,0 };
	int mid = (start + end) / 2;
	pair<long long, long long>leftChild = query(start, mid, node * 2, left, right);
	pair<long long, long long>rightChild = query(mid + 1, end, node * 2 + 1, left, right);
	return { min(leftChild.first,rightChild.first),max(leftChild.second,rightChild.second) };

}

int main() {
	FAST_IO;

	cin >> n >> m;

	h = (int)ceil(log2(n));
	tree.resize(1 << (h + 1), { 1e9,0 });

	h = 1 << h;

	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		update(i, num);
	}

	for (int i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		pair<long long, long long>answer = query(1, h, 1, a, b);
		cout << answer.first << " " << answer.second << '\n';
	}

	return 0;
}
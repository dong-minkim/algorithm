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

long long n,m,h;

vector<long long> arr;
vector<pair<long long, long long>> tree;

pair<long long, long long> compare(pair<long long, long long>one, pair<long long, long long>other) {

	if (one.first < other.first) return one;
	else if (one.first > other.first) return other;
	else {
		if (one.second < other.second) return one;
		else return other;
	}

}

void update(long long idx, long long val) {
	idx += h;
	tree[idx] = {val,idx};
	while (idx > 1) {
		idx /= 2;
		tree[idx] = compare(tree[idx * 2], tree[idx * 2 + 1]);
	}
}

pair<long long, long long> query(int start, int end, int node, int left, int right) {
	if (end < left || right < start) return { 1e9,100001 };
	if (left <= start && end <= right) return tree[node];
	int mid = (end + start) / 2;
	return compare(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}



int main() {
	FAST_IO;

	cin >> n;
	h = ceil(log2(n));
	tree.resize(1 << (h + 1));
	arr.resize(n + 1);
	h = 1 << h;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}
	cin >> m;

	for (int i = 0; i < m; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) update(b - 1, c);
		else {
			pair<long long,long long> result = query(1, h, 1, b, c);
			cout << result.second - h + 1 << '\n';
		}
	}
	

	return 0;
}
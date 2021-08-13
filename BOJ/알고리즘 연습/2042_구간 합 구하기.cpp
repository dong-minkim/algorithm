#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

long long n, m, k;
int h;

vector<long long> tree;
vector<long long> arr;

//int init(int start, int end, int node) {
	
	//if (start == end) return tree[node] = arr[start];
	//int mid = (start + end) / 2;
	//return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);

//}

void update(int idx, long long val) {
	idx += h;
	tree[idx] = val;
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
	cin >> n >> m >> k;

	h = (int)ceil(log2(n));
	tree.resize(1 << (h + 1));
	h = 1 << h;
	arr.resize(n + 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		update(i, arr[i]);
	}

	//init(0, n - 1, 1);

	for (int i = 0; i < m + k; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c);
		}
		else {
			cout<< query(1, h, 1, b , c )<<'\n';
		}
	}
	return 0;
}
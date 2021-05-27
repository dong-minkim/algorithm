#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> parent;

int find(int x) {  //가장 위에 있는 부모 찾기
	if (parent[x] == x) return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {  //합병
	a = find(a);
	b = find(b);
	if (a == b) return;
	parent[b] = a;
}

string answer(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return "YES";
	else return "NO";
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		parent.push_back(i);
	}

	for (int i = 0; i < m; i++) {
		int flag, a, b;
		cin >> flag >> a >> b;
		if (flag == 0) merge(a, b);
		else cout << answer(a, b) << '\n';
	}

	return 0;
}
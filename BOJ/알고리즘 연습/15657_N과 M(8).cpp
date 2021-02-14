#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int n, m;
int check[9] = { 0, };
vector<int> v;
vector<int> v2;
void solution(int index, int x) {
	if (x == m) {
		for (int i = 0; i < m; i++) {
			cout << v[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = index; i <= n; i++) {

		v.push_back(v2[i - 1]);
		solution(i, x + 1);

		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v2.push_back(num);
	}
	sort(v2.begin(), v2.end());
	solution(1, 0);

	return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	cin.tie(0); ios::sync_with_stdio(false);
	vector<int> v;
	int N, M;
	int num;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> num;
		v.push_back(num);
	}
	for (int j = 0; j < M; j++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}

	return 0;
}
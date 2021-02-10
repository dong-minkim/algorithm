#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	int n;
	int num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		cout << v[i] << '\n';
	}

	return 0;
}
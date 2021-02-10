#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n;
	int num;
	cin >> n;
	vector<int> a;
	vector<int> b;
	for (int i = 0; i < n; i++) {
		cin >> num;
		a.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		cin >> num;
		b.push_back(num);
	}
	sort(a.begin(), a.end());

	//sort(v.begin(),v.end(),greater<자료형>()); 내림차순 정렬
	sort(b.begin(), b.end(), greater<>());
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += a[i] * b[i];
	}

	cout << ans << '\n';

	return 0;
}
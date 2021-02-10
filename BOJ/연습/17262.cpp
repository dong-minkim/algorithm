#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	vector<int> start;
	vector<int> end;

	int n;
	cin >> n;
	int num, num2;
	for (int i = 0; i < n; i++) {
		cin >> num >> num2;
		start.push_back(num);
		end.push_back(num2);
	}
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());

	int ans;
	ans = start.back() - end.front();
	if (ans < 0) ans = 0;
	cout << ans << '\n';

	return 0;
}
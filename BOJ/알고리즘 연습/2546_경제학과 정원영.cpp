#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int T;
	int cnt = 0;
	double num;
	vector<double> c_stu;
	vector<double> e_stu;
	double c_sum = 0;
	double e_sum = 0;
	cin >> T;
	while (T--) {
		e_sum = 0;
		c_sum = 0;
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> num;
			c_sum += num;
			c_stu.push_back(num);
		}
		c_sum /= n;

		for (int i = 0; i < m; i++) {
			cin >> num;
			e_sum += num;
			e_stu.push_back(num);
		}
		e_sum /= m;
		cnt = 0;

		for (int i = 0; i < n; i++) {
			if (c_stu[i]<c_sum && c_stu[i]>e_sum) cnt++;
		}
		cout << cnt << '\n';
		c_stu.clear();
		e_stu.clear();
	}



	return 0;
}
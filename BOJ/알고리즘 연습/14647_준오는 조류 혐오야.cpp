#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[500][500];
int main()
{
	int n, m;
	int num;
	int hap = 0;
	int max_ = 0;
	int col = 0;
	int row = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		row = 0;
		for (int j = 0; j < m; j++) {
			int cnt = 0;
			cin >> num;
			while (num > 0) {
				if (num % 10 == 9) cnt++;
				num /= 10;
			}
			arr[i][j] = cnt;
			row += arr[i][j];
		}
		max_ = max(row, max_);

	}
	for (int i = 0; i < m; i++) {
		col = 0;
		for (int j = 0; j < n; j++) {
			col += arr[j][i];
			hap += arr[j][i];
		}
		max_ = max(max_, col);

	}
	int result = hap - max_;

	cout << result << '\n';
	return 0;
}
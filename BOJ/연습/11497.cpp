#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int T;
	cin >> T;
	int num;
	int result = 0;
	vector<int> v;
	for (int i = 0; i < T; i++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> num;
			v.push_back(num);
		}
		//내림차순으로 정렬하여 인접하는 통나무 차를 구하기 쉽도록함
		sort(v.begin(), v.end(), greater<>());
		for (int i = 0; i < n - 2; i++) {
			if (i == 0) {
				result = max(v[i] - v[i + 1], v[i] - v[i + 2]);
			}
			else {
				result = max(result, v[i] - v[i + 2]);
			}
		}
		result = max(result, v[n - 1] - v[n - 2]);
		cout << result << '\n';
		v.clear();
	}

	return 0;
}
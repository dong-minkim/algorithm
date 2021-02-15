#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int N, C;
vector<int> house;

bool solution(int mid) {
	int tmp = house[0];
	int cnt = 1;
	for (int i = 1; i < N; i++) {
		if (house[i] - tmp >= mid) {
			tmp = house[i];
			cnt++;
		}
	}
	if (cnt >= C) {
		return true;
	}
	return false;

}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		house.push_back(num);
	}
	//이분탐색을 하기 위해서 정렬!
	sort(house.begin(), house.end());

	int left = 1;
	int right = house.back() - house.front();
	int result = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (solution(mid)) {
			left = mid + 1;
			result = max(result, mid);
		}
		else right = mid - 1;
	}
	cout << result << '\n';

	return 0;
}
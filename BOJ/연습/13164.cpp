#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int stu;
	int n;
	int height;
	int tmp, res;
	vector<int> v;
	cin >> stu >> n;

	//학생들 사이의 키를 입력받음
	for (int i = 0; i < stu; i++) {
		cin >> height;
		if (i != 0) {
			res = height - tmp;
			v.push_back(res);
			tmp = height;
		}
		else tmp = height;
	}
	//학생들 키 차이를 정렬
	sort(v.begin(), v.end());
	int sum = 0;

	//정렬한 작은 수부터 묶으면 된다.
	for (int i = 0; i < stu - n; i++) {
		sum += v[i];
	}

	cout << sum << '\n';

	return 0;
}
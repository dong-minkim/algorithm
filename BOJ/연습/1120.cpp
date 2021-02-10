#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;


int main()
{
	string a;
	string b;
	int min = 100;
	int cnt;
	cin >> a >> b;
	//문자열 b를 가만히 두고 a를 i크기 만큼 옮기며 비교
	for (int i = 0; i <= b.size() - a.size(); i++) {
		cnt = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[j + i]) cnt++;
		}

		if (min >= cnt) min = cnt;
	}
	cout << min << '\n';

	return 0;
}
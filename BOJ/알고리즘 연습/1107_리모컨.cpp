#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
int arr[10] = { 0, };

//고장난 키가 없으면 1 반환
int check(int n) {
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++) {
		if (arr[s[i] - 48]) {
			return 0;
		}
	}
	return 1;
}

int main()
{
	int N;
	cin >> N;
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		//고장난 버튼
		arr[n] = 1;
	}

	//채널 100부터 시작하여 방향키만 움직일 때
	int min_ = abs(N - 100);
	for (int i = 0; i <= 1000000; i++) {
		//고장난 버튼이 없을 때
		if (check(i)) {
			int tmp = abs(N - i) + to_string(i).length();
			min_ = min(min_, tmp);
		}
	}
	cout << min_ << '\n';

	return 0;
}
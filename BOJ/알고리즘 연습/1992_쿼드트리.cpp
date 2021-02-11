#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int arr[65][65];

void count(int x, int y, int length) {
	int cnt = 0;
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			if (arr[i][j]) {
				cnt++;
			}
		}
	}

	if (!cnt) cout << 0;
	else if (cnt == length * length) cout << 1;
	else {
		//1 -> 2 -> 4 -> 3 사분면 순
		cout << "(";
		count(x, y, length / 2);
		count(x, y + length / 2, length / 2);
		count(x + length / 2, y, length / 2);
		count(x + length / 2, y + length / 2, length / 2);
		cout << ")";
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	string str;
	//문자열로 받아 처리
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
	count(0, 0, N);
	return 0;
}
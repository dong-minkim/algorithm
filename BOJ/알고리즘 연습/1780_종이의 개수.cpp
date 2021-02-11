#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int arr2[3] = { 0, };
int arr[2187][2187];
void rec(int x, int y, int length) {
	//
	int cnt = 0;
	int cnt2 = 0;
	int cnt3 = 0;
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + length; j++) {
			//1일 때
			if (arr[i][j] == 1) {
				cnt++;
			}
			//0일 때
			if (arr[i][j] == 0) {
				cnt3++;
			}
			//-1일 때
			if (arr[i][j] == -1) cnt2++;
		}
	}
	//0
	if (cnt3 == length * length) arr2[1]++;
	//1
	else if (cnt == length * length) arr2[2]++;
	//-1
	else if (cnt2 == length * length) arr2[0]++;
	//9등분으로 나눠 재귀를 돌린다.
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				rec(x + (length / 3) * i, y + (length / 3) * j, length / 3);
			}
		}
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	rec(0, 0, N);

	for (int i = 0; i < 3; i++) {
		cout << arr2[i] << '\n';
	}


	return 0;
}
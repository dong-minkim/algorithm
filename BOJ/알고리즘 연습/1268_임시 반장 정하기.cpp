#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[1000][5] = { 0, };
int arr2[1000][1000] = { 0, };
int main()
{
	int n;
	cin >> n;

	//i번 학생이 j학년 때 몇 반이었는지.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	//각 학년(1~5 학년) 별로 비교
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				//j번 학생과 k번 학생의 i학년 일 경우 반이 같을때
				if (arr[j][i] == arr[k][i]) {
					arr2[j][k] = 1;
					arr2[k][j] = 1;
				}
			}

		}
	}
	int res = -1;
	int tmp = -1;
	int i;
	for (i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			//같은 반인 학생이 있는 경우
			if (arr2[i][j]) cnt++;
		}
		if (cnt > tmp) {
			res = i + 1;
			tmp = cnt;
		}
	}

	cout << res << '\n';

	return 0;
}
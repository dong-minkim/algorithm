#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;
int arr[9][9];

vector<pair<int, int>> v;
int check(int row, int col, int num);
void solution(int n);
int main()
{
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j];
			//스도쿠 칸이 비어있을 경우 v에 넣는다.
			if (arr[i][j] == 0) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	solution(0);

	return 0;
}
void solution(int n) {
	//비어있는 칸 만큼 다 돌았을 때 출력 후 종료
	if (n == v.size()) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << '\n';
		}
		//종료
		exit(0);
	}

	int row = v[n].first;
	int col = v[n].second;
	for (int i = 1; i <= 9; i++) {
		//check후 숫자 기입하고 다음 빈 칸으로 넘어간다.
		if (check(row, col, i) == 1) {
			arr[row][col] = i;
			solution(n + 1);
		}
	}
	arr[row][col] = 0;
}
int check(int row, int col, int num) {
	//스도쿠 규칙1: 자기를 포함한 행 or 열에 같은 숫자가 있으면 안된다.
	for (int i = 0; i < 9; i++) {
		if (num == arr[row][i] || num == arr[i][col]) return 0;
	}
	//스도쿠 규칙2:  3x3칸안에 같은 숫자가 있으면 안된다.
	int x = (row / 3) * 3;
	int y = (col / 3) * 3;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (arr[i][j] == num) return 0;
		}
	}

	//위 규칙을 전부 통과하면 숫자를 기입할 수 있으므로 1 반환!!
	return 1;
}
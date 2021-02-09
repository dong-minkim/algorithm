#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[101][101] = { 0, };
int main()
{
	int T;
	cin >> T;
	int x, y, w, h;
	for (int i = 0; i < T; i++) {
		cin >> x >> y >> w >> h;
		for (int j = 0; j < w; j++) {
			for (int k = 0; k < h; k++) {
				//해당하는 범위에 N번째 종이임을 표시
				arr[x + j][y + k] = i + 1;
			}
		}
	}
	int cnt = 1;
	int ans;
	while (cnt <= T) {
		ans = 0;
		for (int i = 0; i < 101; i++) {
			for (int j = 0; j < 101; j++) {
				//cnt번째 종이일 경우 넓이(ans)를 증가시킴
				if (arr[i][j] == cnt) ans++;
			}
		}
		cout << ans << '\n';
		cnt++;
	}
	return 0;
}
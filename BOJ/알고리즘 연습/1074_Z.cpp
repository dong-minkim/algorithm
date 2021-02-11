#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;
int N, r, c;
int cnt = 0;
void count(int x, int y, int length) {
	if (x == r && y == c) {
		cout << cnt << '\n';
		return;
	}
	if (x <= r && r < x + length && y <= c && c < y + length) {
		count(x, y, length / 2);
		count(x, y + length / 2, length / 2);
		count(x + length / 2, y, length / 2);
		count(x + length / 2, y + length / 2, length / 2);
	}
	else {
		cnt += length * length;
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> N >> r >> c;

	count(0, 0, pow(2, N));
	return 0;
}
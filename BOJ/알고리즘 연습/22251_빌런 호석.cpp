#include<iostream>
#include<vector>
#include<string>

using namespace std;

int num[10][7] = {
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};
string str_x;
int n, k, p, x;
int cnt[10][10] = { 0, };

int solution(int digit , int left) {

	//결과
	if (str_x.size() == digit) {
		if (stoi(str_x) == x) return 0; //같은 수면 +0
		else if (1 <= stoi(str_x) && stoi(str_x) <= n) return 1; //수를 더함
		else return 0;
	}

	int sum = 0;
	int nowNum = str_x[digit] - '0';

	for (int i = 0; i < 10; i++) { //수 0~9까지 비교

		if (nowNum == i) { // 비교하는 수가 같으면
			sum += solution(digit + 1, left); //자릿수 증가, 남은 반전 수
		}
		if (nowNum != i) { // 비교하는 수가 다르면
			if (cnt[nowNum][i] <= left) { 
				str_x[digit] = i + '0'; //0~9까지 비교
				sum += solution(digit + 1, left - cnt[nowNum][i]);
				str_x[digit] = nowNum + '0'; //원래 대로
			}
		}
	}

	return sum;
}

int main()
{
	cin >> n >> k >> p >> x;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (i == j) continue;
			for (int u = 0; u < 7; u++) {
				if (num[i][u] != num[j][u]) {
					cnt[i][j]++;
				}
			}
		}
	}

	str_x = to_string(x);

	while (str_x.size() < k) str_x.insert(str_x.begin(), '0');
	
	cout<<solution(0 , p)<<'\n';

	return 0;
}
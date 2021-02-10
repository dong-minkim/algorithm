#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

int main()
{
	string num;
	cin >> num;
	int sum = 0;
	int len = num.length();
	if (len == 1) {
		cout << num << '\n';
		return 0;
	}

	for (int i = 1; i < len; i++) {
		sum += i * (pow(10, i - 1) * 9);
	}
	//stoi() : string -> int ·Î º¯È¯
	sum += (stoi(num) - pow(10, len - 1) + 1) * len;

	cout << sum << '\n';

	return 0;
}
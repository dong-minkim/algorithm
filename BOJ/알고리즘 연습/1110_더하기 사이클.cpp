#include<iostream>
using namespace std;

int main()
{
	int n;
	int cnt = 1;
	int a, b, c;
	int ans;

	cin >> n;

	ans = n;

	n = ((n % 10) * 10) + (n / 10 + n % 10) % 10;

	while (ans != n) {
		if (n < 10) a = 0;
		else a = n / 10;
		b = n % 10;
		c = (b * 10) + (a + b) % 10;

		n = c;

		cnt++;
	}

	cout << cnt;

	return 0;
}
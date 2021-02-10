#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>
using namespace std;

//최대 공약수에 따른다.
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
int main()
{
	int T;
	cin >> T;
	int a, b, c, d;
	int j;
	for (int i = 0; i < T; i++) {
		cin >> a >> b >> c >> d;
		int lcm = a * b / gcd(a, b);
		for (j = c; j <= lcm; j += a) {
			int tmp = ((j - d) % b == 0);
			if (tmp == true) {
				cout << j << '\n';
				break;
			}
		}
		if (j > lcm) {
			cout << -1 << '\n';
		}
	}

	return 0;
}
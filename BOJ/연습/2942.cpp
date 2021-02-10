#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

//유클리드 호제법
long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}
int main()
{
	long long a, b;
	cin >> a >> b;
	long long c = gcd(a, b);
	for (int i = 1; i <= c; i++) {
		if (c % i == 0) {
			cout << i << ' ' << a / i << ' ' << b / i << '\n';
		}
	}
	return 0;
}
#include<iostream>
using namespace std;

int main()
{
	int n;
	int x = 1;

	cin >> n;

	if (x == n) {
		cout << 1 << '\n';
		return 0;
	}

	while (x < n) {
		x *= 2;
	}
	if (x == n) cout << 1 << '\n';
	else cout << 0 << '\n';

	return 0;
}
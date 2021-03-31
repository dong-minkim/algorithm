#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

using namespace std;

int main()
{
	int t;
	int a, b;
	cin >> t;
	while (t--) {
		cin >> a >> b;
		int tmp;
		tmp = a | b;
		cout << tmp << '\n';
	}
	return 0;
}
#include<iostream>
using namespace std;
int main()
{
	int cnt = 0;
	string s;
	for (int i = 0; i < 8; i++) {
		cin >> s;
		if (i % 2 == 1) {
			for (int j = 1; j < 8; j += 2)
			{
				if (s[j] == 'F') cnt++;
			}
		}
		else {
			for (int j = 0; j < 8; j += 2)
			{
				if (s[j] == 'F') cnt++;
			}
		}
	}

	cout << cnt << '\n';

	return 0;
}
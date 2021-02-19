#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int len = (s.length() / 2) * 2;

	while (len > 0) {
		for (int i = 0; i <= s.length() - len; i++) {
			int sum_1 = 0;
			int sum_2 = 0;
			for (int j = i; j < (len / 2) + i; j++) {
				sum_1 += s[j];
			}
			for (int k = (len / 2) + i; k < len + i; k++) {
				sum_2 += s[k];
			}
			if (sum_1 == sum_2) {
				cout << len << '\n';
				return 0;
			}

		}
		len -= 2;
	}


	return 0;
}
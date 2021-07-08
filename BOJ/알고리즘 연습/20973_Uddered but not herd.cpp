#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	string str1;
	cin >> str1;

	string str2;
	cin >> str2;

	int ans = 0;
	int cnt = 0;
	while (1) {

		for (int i = 0; i < str1.length(); i++) {
			if (str1[i] == str2[cnt]) {
				cnt++;
			}
		}
		ans++;
		if (cnt == str2.length()) break;
	}

	cout << ans << '\n';
	return 0;
}
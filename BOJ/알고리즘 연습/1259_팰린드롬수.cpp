#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s;
	while (s != "0") {

		cin >> s;
		string tmp = s;
		reverse(s.begin(), s.end());
		if (s != "0") {
			if (tmp == s) cout << "yes\n";
			else cout << "no\n";
		}
	}

	return 0;
}
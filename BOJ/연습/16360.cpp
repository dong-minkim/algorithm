#include<iostream>
#include<string>
using namespace std;
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T;
	cin >> T;
	string s;

	for (int i = 0; i < T; i++) {
		cin >> s;
		char word = s[s.size() - 1];
		if (word == 'a' || word == 'o' || word == 'u') {
			s += "s";
		}
		else if (word == 'i' || word == 'y') {
			s[s.size() - 1] = 'i';
			s += "os";
		}
		else if (word == 'l' || word == 'r' || word == 'v') {
			s += "es";
		}
		else if (word == 't' || word == 'w') {
			s += "as";
		}
		else if (word == 'n' || (s[s.size() - 2] == 'n' && word == 'e')) {
			if (word == 'n') {
				s[s.size() - 1] = 'a';
				s += "nes";
			}
			else {
				s[s.size() - 2] = 'a';
				s[s.size() - 1] = 'n';
				s += "es";
			}
		}
		else {
			s += "us";
		}
		cout << s << '\n';
	}

	return 0;
}
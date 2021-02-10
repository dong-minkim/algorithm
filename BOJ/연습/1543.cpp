#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string s;
	string word;
	getline(cin, s);
	getline(cin, word);
	int cnt = 0;
	if (s.size() < word.size()) {
		cnt = 0;
	}
	else {
		for (int i = 0; i <= s.size() - word.size();) {
			bool flag = true;
			for (int j = 0; j < word.size(); j++) {
				if (s[i + j] != word[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				cnt++;
				i += word.size();
			}
			else i++;
		}
	}
	cout << cnt << '\n';

	return 0;
}
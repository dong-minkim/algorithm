#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string s;
string c;
vector<string> v;
int tmp;
int sum = 0;

void printf() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == "H") sum += 1;
		else if (v[i] == "C")sum += 12;
		else if (v[i] == "O")sum += 16;
		else sum += stoi(v[i]);
	}
	cout << sum << '\n';
}
int main() {
	//H:1 C:12 O:16
	cin >> s;
	int cnt = 0;
	while (cnt != s.size()) {
		c = s[cnt];
		if (c == "H" || c == "C" || c == "O" || c == "(") {
			v.push_back(c);
		}
		else if (c == ")") {
			int tmp = 0;
			while (v.back() != "(") {
				if (v.back() == "H") tmp += 1;
				else if (v.back() == "C") tmp += 12;
				else if (v.back() == "O") tmp += 16;
				else tmp += stoi(v.back());
				v.pop_back();
			}
			v.pop_back();
			v.push_back(to_string(tmp));
		}

		else if ("2" <= c && c <= "9") {
			tmp = 0;
			if (v.back() == "H") tmp = 1;
			else if (v.back() == "C") tmp = 12;
			else if (v.back() == "O") tmp = 16;
			else tmp = stoi(v.back());

			tmp *= stoi(c);
			v.pop_back();
			//to_string 문자열로 바꾸는
			v.push_back(to_string(tmp));
		}
		cnt++;
	}
	printf();

	return 0;
}
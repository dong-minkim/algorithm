#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
	FAST_IO;

	string str;
	cin >> str;
	bool flag = true;
	string tmp = "";

	int Answer = 0;

	for (int i = 0; i <= str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (flag == false)
				Answer -= stoi(tmp);
			else
				Answer += stoi(tmp);

			tmp = "";

			if (str[i] == '-') flag = false;

			
			continue;
		}
		tmp += str[i];
	}

	cout << Answer << '\n';

	return 0;
}
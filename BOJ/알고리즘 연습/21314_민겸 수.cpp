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

int main(){
	FAST_IO;

string s;
cin >> s;

string AnswerMax = "";
string AnswerMin = "";

int cnt = 0;
for (int i = 0; i < s.size(); i++) {
	if (cnt == 0 && s[i] == 'K') {
		AnswerMin += '5';
		AnswerMax += '5';
	}


	else if (s[i] == 'M' && i == s.size() - 1) {
		if (cnt == 0) AnswerMin += '1';
		else if (s[i - 1] == 'M') AnswerMin += '0';
		else AnswerMin += '1';



		for (int j = 0; j <= cnt; j++) {
			AnswerMax += '1';
		}
	}

	else if (s[i] == 'M') {
		cnt++;
		if (i != 0 && s[i - 1] == 'M') {
			AnswerMin += '0';
			continue;
		}
		AnswerMin += '1';
	}

	else if (s[i] == 'K') {
		AnswerMin += '5';
		for (int j = 0; j <= cnt; j++) {
			if (j == 0) AnswerMax += '5';
			else AnswerMax += '0';
		}
		cnt = 0;
	}
}

cout << AnswerMax << '\n';
cout << AnswerMin << '\n';

return 0;
}
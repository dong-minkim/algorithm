#include<iostream>
#include<string>
using namespace std;
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string answer;
	string input;
	getline(cin, input);
	string passwd;
	cin >> passwd;
	int j = 0;

	for (int i = 0; i < input.size(); i++) {
		if (j == passwd.size()) j = 0;

		if (input[i] == ' ') {
			answer += ' ';

		}
		else {
			//아스키코드 활용
			if (input[i] - passwd[j] <= 0) {
				answer += 26 + int(input[i]) - int(passwd[j]) + 96;
			}
			else {
				answer += int(input[i]) - int(passwd[j]) + 96;
			}
		}
		j++;
	}
	cout << answer;

	return 0;
}
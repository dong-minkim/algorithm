#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
char arr[100][100];
int main()
{
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = b - 1; i >= 0; i--) {
		for (int j = 0; j < a; j++) {
			if (arr[j][i] == 45) cout << '|';
			else if (arr[j][i] == 124) cout << '-';
			else if (arr[j][i] == 47) cout << '\\';
			else if (arr[j][i] == 92) cout << '/';
			else if (arr[j][i] == '^') cout << '<';
			else if (arr[j][i] == '<') cout << 'v';
			else if (arr[j][i] == 'v') cout << '>';
			else if (arr[j][i] == '>')cout << '^';
			else cout << arr[j][i];
		}
		cout << '\n';
	}

	return 0;
}
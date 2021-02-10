#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char string[250];

	while (1) {
		//띄워쓰기도 입력받는다.
		scanf("%[^\n]", string);
		int arr[27] = { 0, };
		int cnt = 0;

		if (string[0] == '#') return 0;

		//아스키코드 사용
		for (int i = 97; i <= 122; i++) {
			for (int j = 0; j < strlen(string); j++) {
				if (string[j] == i || string[j] == i - 32) {
					if (arr[i - 97] == 0) cnt++;
					arr[i - 97]++;
				}
			}
		}
		cout << cnt << '\n';
		getchar();
	}

	return 0;
}
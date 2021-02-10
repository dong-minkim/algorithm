#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	string arr[5];
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			//j줄의 길이(글자 수)보다 i가 크면 그냥 넘어가고
			if (i + 1 > arr[j].length()) continue;
			//글자가 공백이 아니면 출력
			if (arr[j][i] != NULL) cout << arr[j][i];
		}
	}

	return 0;
}
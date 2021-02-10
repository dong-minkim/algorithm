#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int arr[9];
	int sum = 0;
	int flag = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	//총 합에서 2명을 뺀 값이 100일 때
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if ((sum - arr[i] - arr[j]) == 100) {
				arr[i] = 101;
				arr[j] = 101;
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
	}
	sort(arr, arr + 9);
	for (int i = 0; i < 7; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}
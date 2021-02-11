#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int arr[3];
	int num;
	int cnt;
	cin >> num;
	if (num <= 99) {
		cnt = num;
	}
	else {
		cnt = 99;
		for (int i = 100; i <= num; i++) {

			arr[0] = i / 100;
			arr[1] = (i / 10) % 10;
			arr[2] = i % 10;
			if (arr[0] - arr[1] == arr[1] - arr[2]) {
				cnt++;
			}

		}
	}
	cout << cnt << '\n';
	return 0;
}
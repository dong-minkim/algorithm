#include<iostream>
using namespace std;

int main()
{
	int n;
	int mul = 1;
	int arr[10] = { 0, };

	for (int i = 0; i < 3; i++) {
		cin >> n;
		mul *= n;
	}
	while (mul != 0) {
		arr[mul % 10]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << '\n';
	}

	return 0;
}
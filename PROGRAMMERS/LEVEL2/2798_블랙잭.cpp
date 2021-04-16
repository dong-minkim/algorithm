#include<iostream>

using namespace std;

int main()
{
	int card;
	int maxSum;
	int result = 0;

	int arr[100];

	cin >> card >> maxSum;

	for (int i = 0; i < card; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < card - 2; i++) {
		for (int j = i + 1; j < card - 1; j++) {
			for (int k = j + 1; k < card; k++) {
				if (arr[i] + arr[j] + arr[k] <= maxSum && maxSum - (arr[i] + arr[j] + arr[k]) < maxSum - result) {
					result = arr[i] + arr[j] + arr[k];
				}
			}
		}
	}
	cout << result;

	return 0;
}
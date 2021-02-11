#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[10000];
int main()
{
	int N, M;
	int sum = 0;
	int tmp = 0;
	int cnt = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		while (sum > M) {

			sum -= arr[tmp];
			tmp++;
		}
		if (sum == M) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
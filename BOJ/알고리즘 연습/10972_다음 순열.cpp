#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int arr[10001];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//다음 순열(next_permutation)이 존재하면 그 순열 순서대로 출력
	//next_permutation 한 순간 다음 순열로 넘어감

	if (next_permutation(arr, arr + n) == true) {
		for (int i = 0; i < n; i++) cout << arr[i] << ' ';
	}
	else cout << -1 << '\n';

	return 0;
}
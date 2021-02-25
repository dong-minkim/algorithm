#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int arr[21] = { 1,2,4,7,14, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 5; i <= n; i++) {
		if (i % 2 == 1) arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
		else arr[i] = arr[i - 1] * 2;
	}
	cout << arr[n - 1] << '\n';


	return 0;
}
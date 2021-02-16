#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long arr[91];
	arr[0] = 1, arr[1] = 1;
	for (int i = 2; i <= 90; i++) {
		//dp·Î
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	long long num;
	cin >> num;
	cout << arr[num - 1] << '\n';


	return 0;
}
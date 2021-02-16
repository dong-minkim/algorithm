#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;
long long arr[1000000] = { 0,0,1,1, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long num;
	cin >> num;
	for (int i = 4; i <= num; i++) {
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0) arr[i] = min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0) arr[i] = min(arr[i], arr[i / 3] + 1);
	}
	cout << arr[num] << '\n';


	return 0;
}
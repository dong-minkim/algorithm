#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int x;
	long long sum = 0;
	long long tmp;
	cin >> n;

	//1부터 n-1 까지의 합
	tmp = (long long)n * ((long long)n - 1) / 2;
	
	//1부터 n-1 까지의 합 + 중복된 숫자
	for (int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
	}

	//result: 중복된 숫자
	int result = sum - tmp;

	cout << result << '\n';
	return 0;
}
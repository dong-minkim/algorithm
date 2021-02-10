#include<iostream>
#include<string>
using namespace std;
long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);

}
int main()
{
	int n;
	int T;
	cin >> T;
	int arr[100];
	long long a, b;
	for (int i = 0; i < T; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(arr[i], arr[j]);
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
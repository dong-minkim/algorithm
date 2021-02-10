#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int num;
	long long sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			sum += num;
		}
	}

	cout << sum << '\n';

	return 0;
}

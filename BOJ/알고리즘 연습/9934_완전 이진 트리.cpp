#include<iostream>
#include<vector>
#include<cmath>


using namespace std;
vector<int> v;

int main()
{
	int k;
	cin >> k;
	

	for (int i = 0; i < pow(2, k) - 1; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	for (int i = k - 1; i >= 0; i--) {
		int tmp = pow(2, i + 1);
		for (int j = pow(2, i); j < pow(2, k); j+=tmp) {
			cout << v[j-1] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
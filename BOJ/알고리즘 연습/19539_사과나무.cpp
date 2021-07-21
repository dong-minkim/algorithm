#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int n;
vector<int> tree;
int water_2 = 0, water_1 = 0;

int main()
{
	int sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int length;
		cin >> length;
		tree.push_back(length);

		water_2 += length / 2;
		water_1 += length % 2;
	}

	if (water_2 >= water_1 && (water_2 - water_1) % 3==0) cout << "YES" << '\n';
	else cout << "NO" << '\n';


	return 0;
}
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int hole;
vector<int> v;

int main()
{
	while (cin>>hole) {
		hole *= 1e7;
		int flag = false;
		int num;
		cin >> num;
		for (int i = 0; i < num; i++) {
			int number;
			cin >> number;
			v.push_back(number);
		}
		sort(v.begin(), v.end());
		int l = 0, r = v.size() - 1;

		
		while (l < r) {
			int sum = v[r] + v[l];
			if (sum == hole) {
				cout << "yes " << v[l] << " " << v[r] << '\n';
				flag = true;
				break;
			}
			else if (sum < hole) l++;
			else r--;
		}
		if (flag == false) cout << "danger" << '\n';
	}


	return 0;
}
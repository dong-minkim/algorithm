#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<long long> cow;
vector<long long> house;
vector<long long> tmp;

int main()
{
	long long N;
	long long answer = 1;
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		cow.push_back(num);
	}

	for (int i = 0; i < N; i++) {
		long long num;
		cin >> num;
		house.push_back(num);
	}

	sort(cow.begin(), cow.end(), greater<>());

	
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			if (cow[i] <= house[j]) cnt++;
		}
		tmp.push_back(cnt);
	}

	for (int i = 0; i < N; i++) {
		answer *= (tmp[i] - i);
	}

	cout << answer << '\n';


	return 0;
}
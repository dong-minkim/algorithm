#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int testCase;
	cin >> testCase;

	vector<pair<int, int>> person(testCase);
	vector<int> rank(testCase);

	for (int i = 0; i < testCase; i++) {
		cin >> person[i].first >> person[i].second;
	}

	for (int i = 0; i < testCase; i++) {
		int cnt = 1;
		for (int j = 0; j < testCase; j++) {
			if (person[i].first < person[j].first && person[i].second < person[j].second)
			{
				cnt++;
			}
		}
		rank[i] = cnt++;
	}

	for (int i = 0; i < testCase; i++) {
		cout << rank[i] << " ";
	}

	return 0;
}
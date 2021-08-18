#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
	FAST_IO;

	long long jewelNum,  bagNum, bagWeight;
	vector<pair<long long, long long>> jewel;
	vector<long long> bag;
	
	cin >> jewelNum >> bagNum;

	for (int i = 0; i < jewelNum; i++) {
		long long jewelWeight, jewelPrice;
		cin >> jewelWeight >> jewelPrice;
		jewel.push_back({ jewelWeight,jewelPrice });
	}

	for (int i = 0; i < bagNum; i++) {
		cin >> bagWeight;
		bag.push_back(bagWeight);
	}

	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());

	priority_queue<long long>pq;
	long long n=0;
	long long Answer = 0;
	for (int i = 0; i < bagNum; i++) {
		while (n < jewelNum && jewel[n].first <= bag[i]) {
			pq.push(jewel[n].second);
			n++;
		}
		if (pq.empty()==1)continue;
		else {
			Answer += pq.top();
			pq.pop();
		}
	}

	cout << Answer << '\n';

	return 0;
}
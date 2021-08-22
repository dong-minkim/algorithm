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

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> maleMinus, malePlus, femaleMinus, femalePlus;
	
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > 0) malePlus.push(num);
		else maleMinus.push(-1 * num);
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num > 0) femalePlus.push(num);
		else femaleMinus.push(-1 * num);
	}

	int Answer = 0;

	while(1){
		if (femaleMinus.empty() || malePlus.empty()) break;

		if (malePlus.top() < femaleMinus.top()) {
			malePlus.pop();
			Answer++;
		}
		femaleMinus.pop();
	}

	while(1){
		if (maleMinus.empty() || femalePlus.empty()) break;

		if (femalePlus.top() < maleMinus.top()) {
			femalePlus.pop();
			Answer++;
		}
		maleMinus.pop();
	}

	cout << Answer << '\n';

	return 0;
}
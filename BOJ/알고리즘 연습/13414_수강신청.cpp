#include<iostream>
#include<vector>
#include<map>

using namespace std;

int K, L;
map<int, int> m;
int number[500005];

int main()
{
	cin >> K >> L;

	for (int i = 0; i < L; i++) {
		cin >> number[i];
		if (m.find(number[i]) == m.end()) m.insert({ number[i],i });
		else m[number[i]] = i;
	}

	int cnt = 0;
	for (int i = 0; i < L; i++) {
		if (cnt == K)break;
		else if (m[number[i]] == i) {
			cout << number[i] << '\n';
			cnt++;
		}
	}
	return 0;
}
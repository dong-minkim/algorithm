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

int word[10001];

int main() {
	FAST_IO;
	int n, m;
	cin >> n >> m;
	int remember = 0;

	for (int i = 0; i < 26; i++) {
		remember += (1 << i);
	}

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			word[i] |= (1 << (s[j] - 'a'));
		}
	}

	int num;
	char c;

	for (int i = 0; i < m; i++) {
		int cnt = 0;
		cin >> num >> c;

		remember ^= (1 << (c - 'a'));

		for (int j = 0; j < n; j++) {
			if ((remember & word[j]) != word[j]) {
				continue;
			}
			cnt++;
		}
		cout << cnt << '\n';
	}

	return 0;
}

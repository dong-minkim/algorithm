#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int n;
	string word;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> n >> word;
		for (int j = 0; j < word.size(); j++) {
			if (j != n - 1) cout << word[j];
		}
		cout << '\n';
	}
	return 0;
}
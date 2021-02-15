#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int N, C;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<string> hear;
	vector<string> hearSee;
	string s;
	int cnt = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		hear.push_back(s);
	}
	//듣도 못한 사람을 정렬한다.
	sort(hear.begin(), hear.end());
	
	//듣도 못한 사람들 중에 보도 못한 사람들을 찾아
	//듣도 보도 못한 사람에 push한다.
	for (int i = 0; i < m; i++) {
		cin >> s;

		if (binary_search(hear.begin(), hear.end(), s)) {
			hearSee.push_back(s);
			cnt++;
		}
	}

	//사전순으로 정렬 후
	sort(hearSee.begin(), hearSee.end());

	//출력
	cout << cnt << '\n';
	for (int i = 0; i < hearSee.size(); i++) {
		cout << hearSee[i] << '\n';
	}
	return 0;
}
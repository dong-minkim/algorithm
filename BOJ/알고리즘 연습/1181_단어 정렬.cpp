#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//비교
bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	else return a.size() < b.size();
}

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	int n;
	vector<string> v;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		//중복되는 단어를 제외하고 push한다.
		//find함수는 해당하는 것이 없으면 vector.end()반환
		if (find(v.begin(), v.end(), s) == v.end()) {
			v.push_back(s);
		}
	}
	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}

	return 0;
}
#include<iostream>
#include<set>

using namespace std;

set<pair<int, int>> s;

int main()
{
	int cnt = 0;
	int count = 0;
	int N;
	int A, B;
	cin >> N;
	cin >> A >> B;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		s.insert({ x,y });
	}
	for (auto i = s.begin(); i != s.end(); i++) {
		int a = i->first;
		int b = i->second;
		if (s.find({ a + A,b }) != s.end()) {
			if (s.find({ a,b + B }) != s.end()) {
				if (s.find({ a + A,b + B }) != s.end())
					cnt++;
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}
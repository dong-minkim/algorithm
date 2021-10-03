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

vector<vector<int>> v;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int j_x, j_y;
int f_x, f_y;
queue<pair<int, int>>fire;

int main() {
	FAST_IO;

	int a, b;
	cin >> a >> b;
	v.resize(a);
	for (int i = 0; i < a; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			v[i].push_back(s[j]);
			if (s[j] == 'J') {
				j_y = i; j_x = j;
			}
			if (s[j] == 'F') {
				fire.push({ i,j });
			}
		}
	}

	queue<pair<int, int>> q;
	q.push({ j_y,j_x });

	int time = 0;

	while (1) {
		time++;
		int fire_cnt = fire.size();
		while (fire_cnt--) {
			int y = fire.front().first;
			int x = fire.front().second;
			fire.pop();

			for (int i = 0; i < 4; i++) {
				int Y = y + dy[i];
				int X = x + dx[i];

				if (Y < 0 || Y >= a || X < 0 || X >= b) continue;
				if (v[Y][X] == 'F' || v[Y][X] == '#') continue;
				v[Y][X] = 'F';
				fire.push({ Y,X });
			}
		}

		int j_cnt = q.size();
		if (j_cnt == 0) {
			cout << "IMPOSSIBLE" << '\n';
			return 0;
		}
		while (j_cnt--) {
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int Y = y + dy[i];
				int X = x + dx[i];

				if (Y < 0 || Y >= a || X < 0 || X >= b) {
					cout << time << '\n';
					return 0;
				}
				if (v[Y][X] == 'F' || v[Y][X] == '#' || v[Y][X] == 'J') continue;
				v[Y][X] = 'J';
				q.push({ Y,X });
			}
		}
	}

	return 0;
}
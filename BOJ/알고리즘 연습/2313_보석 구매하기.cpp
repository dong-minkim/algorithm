#include<iostream>
#include<vector>

using namespace std;

int n, L;
vector<int> cost;
int dp[1002][1002]; //전역 변수로 썼을 때, 자동으로 0으로 초기화 된다.
vector<pair<int, int>>answer;
int total = 0;

int main()
{
	cin >> n;
	int num = n;
	while (n--) {
		int left=0, right=0;
		cin >> L;
		int pay = -1e9;
		int order = 1e9;
		cost.resize(L + 1,0);
		for (int i = 1; i <= L; i++) {
			cin >> cost[i];
		}
		for (int i = 1; i <= L; i++) {
			for (int j = i; j <= L; j++) {
				dp[i][j] = dp[i][j - 1] + cost[j];
				if (dp[i][j] > pay) {
					order = j - i;
					pay = dp[i][j];
					left = i;
					right = j;
				}
				else if (dp[i][j] == pay) {
					if (order > j - i) {
						order = j - i;
						pay = dp[i][j];
						left = i; right = j;
					}
				}
			}
		}
		total += pay;
		answer.push_back(make_pair(left, right));
		cost.clear();
	}
	cout << total << '\n';
	for (int i = 0; i < num; i++) {
		cout << answer[i].first << ' ' << answer[i].second << '\n';
	}

	return 0;
}
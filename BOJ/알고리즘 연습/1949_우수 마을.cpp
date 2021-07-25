#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


//시간 초과남
int n;
vector<int> map[10001];
int inhabit[10001] = { 0, };
bool visited[10001];

int dfs(int start, int flag) { //현재 우수 : flag = true
	int ans = 0;
	visited[start] = true;
	//cout << start <<" "<<flag<<" "<< '\n';

	for (int i = 0; i < map[start].size(); i++) {

		int next = map[start][i];

		if (visited[next] == false) {

			if (flag) ans += dfs(next, 0); //현재 우수면 , 다음은 우수아니다.

			//현재 우수아니면 , 다음이 우수가아니거나 다음이 우수다.
			else ans += max(dfs(next, 0), dfs(next, 1) + inhabit[next]);
		}
	}
	visited[start] = false; //여기 다시 생각해보자

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> inhabit[i];
	}

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		map[b].push_back(a);
	}

	int answer_1 = dfs(1, 0);

	fill(visited, visited + n + 2, false);

	int answer_2 = dfs(1, 1) + inhabit[1];

	cout << max(answer_1, answer_2) << '\n';

	return 0;
}
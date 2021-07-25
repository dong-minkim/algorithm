#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


//�ð� �ʰ���
int n;
vector<int> map[10001];
int inhabit[10001] = { 0, };
bool visited[10001];

int dfs(int start, int flag) { //���� ��� : flag = true
	int ans = 0;
	visited[start] = true;
	//cout << start <<" "<<flag<<" "<< '\n';

	for (int i = 0; i < map[start].size(); i++) {

		int next = map[start][i];

		if (visited[next] == false) {

			if (flag) ans += dfs(next, 0); //���� ����� , ������ ����ƴϴ�.

			//���� ����ƴϸ� , ������ ������ƴϰų� ������ �����.
			else ans += max(dfs(next, 0), dfs(next, 1) + inhabit[next]);
		}
	}
	visited[start] = false; //���� �ٽ� �����غ���

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
#include<iostream>
#include<vector>

using namespace std;

int n;
bool visited[500001];
vector<int> edge[500001];
int sum = 0;
void solution(int n,int cnt) {

	if (n == 1 && cnt == 0) visited[1] = true;

	if (edge[n].size() == 1 && n != 1) { //부모 노드 연결 사이즈 하나
		sum += cnt;
		return;
	}

	for (int i = 0; i < edge[n].size(); i++) {
		int next = edge[n][i];
		if (!visited[next]) {
			visited[next] = true;
			solution(next,cnt+1);
			visited[next] = false;
		}
	}

}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	
	solution(1, 0);

	(sum % 2 == 1) ? cout << "Yes" : cout << "No" << '\n';

	return 0;
}
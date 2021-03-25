#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int v, e;
vector<int> arr[20001];
int colored[20001] = { 0, };
int a, b;

int dfs(int v, int color) {
	colored[v] = color;

	for (int i = 0; i < arr[v].size(); i++) {
		int next = arr[v][i];

		if (!colored[next]) {
			//3-color: 다음 색깔은 1이면2 2이면1로 다른 색으로 칠하기 위함.
			//!dfs()인 이유: 재귀로 들어가 이분그래프가 아니라면 이게 시행됨.
			if (!dfs(next, 3 - color)) return false;
		}
		//다음에 칠할 색과 현재 색이 같다면 이분그래프가 아니다.
		else if (colored[next] == colored[v]) return false;
	}
	//위에 조건을 다 통과하면 이분그래프이다.
	return true;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		
		cin >> v >> e;

		//정점 수만큼 모든 정보들 reset
		for (int i = 0; i <= v; i++) {
			arr[i].clear();
			colored[i] = 0;
		}
		
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}

		//이분탐색은 인접한 노드가 다른 색깔 (1, 2)로 칠할 수 있으면 된다.
		for(int i=1;i<=v;i++){
			if (!colored[i]) {
				//처음 색깔 1로 지정.
				if (dfs(i, 1) == false) {
					cout << "NO" << '\n';
					break;
				}
				else cout << "YES" << '\n';
			}
		}
	

	}
	return 0;
}
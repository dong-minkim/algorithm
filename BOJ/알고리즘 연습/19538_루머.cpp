#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n;
vector<int> edge[200001];
int answer[200001];
bool visited[200001];
queue<pair<int, int>> q;

int main()
{
	cin >> n;
	for (int i =1 ; i <= n; i++) {
		int num;
		cin >> num;
		while (num != 0) {
			edge[i].push_back(num);
			cin >> num;
			
		}
		answer[i] = -1;
	}


	int start;
	cin >> start;
	
	for (int i = 0; i < start; i++) {
		int num;
		cin >> num;
		answer[num] = 0; //시작점 시간 초기화
		q.push({ num,0 });
		//visited[num] = true;
	}

	while (!q.empty()) {
		int now = q.front().first;
		int time = q.front().second;
		q.pop();

		for (int i = 0; i < edge[now].size(); i++) {
			int next = edge[now][i];
			if (answer[next] == -1) {
				int around = 0;
				for (int j = 0; j < edge[next].size(); j++) {
					//if (answer[edge[next][j]] != -1 && visited[edge[next][j]] ) around++;
					if (answer[edge[next][j]] != -1 && answer[edge[next][j]]<=time ) around++;
				}
				
				int tmp;
				if (edge[next].size() % 2 == 0) tmp = edge[next].size() / 2;
				else tmp = edge[next].size() / 2 + 1 ;
				
				if (around >= tmp) {
					q.push({ next,time + 1 });
					answer[next] = time + 1;
				}
			}
		}
		/*for (int i = 1; i <= n; i++) {
			if (answer[i] != -1) visited[i] = true;
		}*/

	}

	for (int i = 1; i <= n; i++) {
		cout << answer[i] << " ";
	}



	return 0;
}
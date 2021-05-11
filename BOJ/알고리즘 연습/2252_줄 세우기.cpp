#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> v[32001];
queue<int> q;
int len[32001] = { 0, };

int main()
{
	int N, M; int A, B;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> A >> B;
		v[A].push_back(B);
		len[B]++;
	}
	
	for (int i = 1; i <= N; i++) {
		if (len[i] == 0) q.push(i);
	}
	
	//위상정렬 point
	//그 노드와 연결된 len개수(간선 개수)가 0이어야 다른 노드들과 우선순위
	//비교에서 벗어나므로 len==0일때 q에 push를 한다.
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << ' ';

		for (int i = 0; i < v[now].size(); i++) { //노드 now에 연결되어있는 간선
			int next = v[now][i];   //now노드에 연결된 다음 노드
			len[next]--;            //now노드와 next 노드 연결된 간선을 제거
			if (len[next] == 0) q.push(next); //연결된 간선이 없으면 q에 push
		}
	}



}
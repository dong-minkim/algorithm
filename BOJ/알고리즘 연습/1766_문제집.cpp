#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

vector<int> v[32001];
int in_degree[32001];

//priority_queue<자료형, Container, 비교함수> 변수명
//선언한 자료형 변수들을 비교함수에 따라 정렬
priority_queue<int,vector<int>,greater<int>> pq;

int main()
{
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		in_degree[B]++;
	}

	for (int i = 1; i <= N; i++) {
		if (in_degree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int now = pq.top();
		pq.pop();
		
		cout << now << " ";

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			in_degree[next]--;
			if (in_degree[next] == 0) pq.push(next);
		}
	}
	cout << '\n';

	return 0;
}
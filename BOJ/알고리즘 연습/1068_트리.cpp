#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> edge[51];


int delNode;

int DFS(int now) {
	
	int sub = 0;
	for (int i = 0; i < edge[now].size(); i++) {
		int next = edge[now][i];
		if (next == delNode) continue;
		sub += DFS(next); //현재 노드가 갖고 있는 서브 노드 개수를 더한다.
	}

	if (sub!=0) { //sub노드 개수가 0이라면 말단 노드이기 때문에 1을 더해준다.
		return sub;
	}
	else { //말단노드가 아니라면
		return 1;
	}
}

int main()
{
	int N, rootNode;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;
		if (parent == -1) {
			rootNode = i;
		}
		else edge[parent].push_back(i);
	}

	cin >> delNode;

	if (rootNode == delNode) cout << 0 << '\n';
	else cout << DFS(rootNode) << '\n';


	return 0;
}
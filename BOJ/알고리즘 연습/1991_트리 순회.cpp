#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

pair<int, int> edge[27];


void preorder(int rootNode) {
	if (rootNode + 'A' == '.') return;

	cout << char(rootNode + 'A');

	preorder(edge[rootNode].first);
	preorder(edge[rootNode].second);
}

void inorder(int rootNode) {
	if (rootNode + 65 == '.') return;

	inorder(edge[rootNode].first);

	cout << char(rootNode + 65);

	inorder(edge[rootNode].second);
}

void postorder(int rootNode) {
	if (rootNode + 65 == '.') return;

	postorder(edge[rootNode].first);
	postorder(edge[rootNode].second);

	cout << char(rootNode + 65);
}


int main()
{
	int N;
	char parent, child_1, child_2;

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> parent;
		cin >> child_1 >> child_2;
		edge[parent - 'A']=make_pair(child_1-'A' , child_2-'A' );
	}

	preorder(0); cout << '\n';
	inorder(0); cout << '\n';
	postorder(0); cout << '\n';

	return 0;
}
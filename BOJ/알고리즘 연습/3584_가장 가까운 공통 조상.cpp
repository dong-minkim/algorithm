#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int parent[10001];
int visited[10001];

int main()
{
	int T;
	
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {

		int n;
		cin >> n;
		for (int i = 1; i < n; i++) {
			int a, b;
			cin >> a >> b;
			parent[b] = a; //b의 부모는 a다.
		}

		int x, y;
		cin >> x >> y;
		visited[x] = 1;
		while (1) {
				visited[parent[x]] = 1;
				x = parent[x];
				if (x == 0) break;

		}
		while (1) {
			if (visited[y] == 1) {
				cout << y << '\n';
				break;
			}
			y = parent[y];
		}


		fill(parent, parent + n+2, 0);
		fill(visited, visited + n+2, 0);		
	}



	return 0;
}
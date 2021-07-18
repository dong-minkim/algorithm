#include<iostream>
#include<Vector>

using namespace std;

int arr[101][101];

int main()
{
	int n, m;
	int a, b;
	int cnt;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[b][a] = 1;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (arr[i][k] && arr[k][j])
					arr[i][j] = 1;

	for (int i = 1; i <= n; i++)
	{
		cnt = 0;
		for (int j = 1; j <= n; j++)
			if (!(arr[i][j] || arr[j][i])) cnt++;
		cout << cnt - 1 << '\n';
	}
}
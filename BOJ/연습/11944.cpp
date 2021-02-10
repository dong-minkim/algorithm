#include<iostream>
#include<string>
using namespace std;
int main()
{

	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string N;
	int M;
	cin >> N >> M;
	string answer;


	if (N.size() * stoi(N) >= M)
	{
		int num = M / N.size();
		for (int i = 0; i < num; i++) {
			answer += N;
		}
		for (int i = 0; i < M % N.size(); i++) {
			answer += N[i];
		}
	}
	else {
		for (int i = 0; i < stoi(N); i++) {
			answer += N;
		}
	}

	cout << answer << '\n';

	return 0;
}
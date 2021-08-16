#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int T;

int main() {
	FAST_IO;

	cin >> T;
	while (T--) {

		int n;
		cin >> n;

		vector<int> v(n);

		int mcnt = 0, tcnt = 0;
		int answer1 = 0, answer2 = 0;
		long long Answer = 0;

		for (int i = 0; i < n; i++) cin >> v[i];

		for (int i = 0; i < n; i++) {

			if (v[i] == -1) mcnt++;
			else if (v[i] == -2) {
				mcnt++;
				tcnt++;
			}
			else if (v[i] == 0) { //����
				tcnt = 0;
				mcnt = 0;
				continue; //���� ���� 0�ΰ�� answer�� 1�̸� �ȵǹǷ�
			}
			else if (v[i] == 2) {
				tcnt++;
			}

			if (mcnt % 2 == 0) { //������ ¦������
				                 //���� �ϳ��� 1�ΰ�� 1�� ��� �����ϰ�
				answer1 = max(answer1, tcnt);
				Answer = 1;
			}
		}

		tcnt = mcnt = 0;

		for (int i = n - 1; i >= 0; i--) {
			if (v[i] == -1) mcnt++;
			else if (v[i] == -2) {
				mcnt++;
				tcnt++;
			}
			else if (v[i] == 0) { //����
				tcnt = 0;
				mcnt = 0;
				continue;
			}
			else if (v[i] == 2) {
				tcnt++;
			}

			if (mcnt % 2 == 0) { //������ ¦������
				answer2 = max(answer2, tcnt);
				Answer = 1;
			}
		}

		int answer = max(answer1, answer2); 
		//cout << answer1 << " " << answer2 << '\n';
		
		while (answer--) {
			Answer = Answer * 2 % 1000000007;
		}
		cout << Answer << '\n';
	}

	return 0;
}
#include<iostream>
using namespace std;
int main()
{
ios::sync_with_stdio(false);
cin.tie(NULL);

int sw_n[100];
int num;
cin >> num;
for (int i = 0; i < num; i++) {
	cin >> sw_n[i];
}
int st_n[100][2];
int num2;
cin >> num2;
for (int i = 0; i < num2; i++) {
	cin >> st_n[i][0] >> st_n[i][1];//0:성별 1:스위치 번호
}

for (int i = 0; i < num2; i++) {
	//남학생일 때 규칙
	if (st_n[i][0] == 1) {
		for (int j = 1; j <= num / st_n[i][1]; j++) {
			if (sw_n[j * st_n[i][1] - 1] == 0) sw_n[j * st_n[i][1] - 1] = 1;
			else sw_n[j * st_n[i][1] - 1] = 0;
		}
	}
	//여학생일 때 규칙
	else if (st_n[i][0] == 2) {
		if (sw_n[st_n[i][1] - 1] == 0) sw_n[st_n[i][1] - 1] = 1;
		else sw_n[st_n[i][1] - 1] = 0;

		int left = st_n[i][1] - 2;
		int right = st_n[i][1];
		while (left >= 0 && right < num) {
			if (sw_n[left] == sw_n[right]) {
				if (sw_n[left] == 0) sw_n[left] = 1;
				else sw_n[left] = 0;
				if (sw_n[right] == 0) sw_n[right] = 1;
				else sw_n[right] = 0;
				left--;
				right++;
			}
			else break;
		}
	}
}
for (int i = 0; i < num; i++) {
	cout << sw_n[i] << " ";
	if ((i + 1) % 20 == 0) cout << '\n';
}

return 0;
}
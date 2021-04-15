#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int num = 666;
	int cnt = 1;
	int num_copy;

	while (1) {

		if (n == cnt) break;
		num++;
		num_copy = num;
		int flag = 0;

		while (num_copy) {
			int tmp = num_copy % 10;
			if (tmp == 6) {
				flag++;
			}
			else if (flag < 3) {
				flag = 0;
			}
			num_copy /= 10;
		}
		if (flag >= 3) {
			cnt++;
		}

	}
	cout << num << endl;

	return 0;
}
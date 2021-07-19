#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> hitter[51];
vector<int> order;

int n;
int answer = 0;

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			int num;
			cin >> num;
			hitter[i].push_back(num);
		}
	}

	for (int i = 1; i <= 8; i++) {
		order.push_back(i);
	}
}

int play(vector<int>& order) {
	int score = 0;
	int first_hitter = 0; //이닝 첫번째 타자

	//이닝시작
	for (int innings= 0;innings< n; innings++) { //이닝
		
		int out_cnt = 0;
		bool runner[5] = { false, };

		while (out_cnt != 3) {
			
				if (hitter[innings][order[first_hitter]] == 0) {
					out_cnt++; first_hitter++;
				}

				else if (hitter[innings][order[first_hitter]] == 1) {
					first_hitter++;
					for (int i = 3; i >= 1; i--) {
						if (runner[i] == true) {
							if (i + 1 >= 4) {
								score++; runner[i] = false;
							}
							else { runner[i + 1] = true; runner[i] = false; }
						}
					}
					runner[1] = true;
				}

				else if (hitter[innings][order[first_hitter]] == 2) {
					first_hitter++;
					for (int i = 3; i >= 1; i--) {
						if (runner[i] == true) {
							if (i + 2 >= 4) {
								score++; runner[i] = false;
							}
							else { runner[i + 2] = true; runner[i] = false; }
						}
					}
					runner[2] = true;
				}

				else if (hitter[innings][order[first_hitter]] == 3) {
					first_hitter++;
					for (int i = 3; i >= 1; i--) {
						if (runner[i] == true) {
							if (i + 3 >= 4) {
								score++; runner[i] = false;
							}
							else { runner[i + 3] = true; runner[i] = false; }
						}
					}
					runner[3] = true;
				}
				else { //홈런
					first_hitter++;
					for (int i = 3; i >= 1; i--) {
						if (runner[i] == true) {
							score++; runner[i] = false;
						}
					}
				}
				if (first_hitter > 8) first_hitter = 0;

		}
	}
	return score;
}

int main()
{
	Input();

	do {
		order.insert(order.begin() + 3, 0);

		answer=max(answer,play(order));

		//cout << answer << '\n';
		
		order.erase(order.begin() + 3);
	} while (next_permutation(order.begin(),order.end()));

	cout << answer << '\n';

	return 0;
}
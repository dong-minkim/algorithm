#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n, x;
vector<int> v;

int main()
{
	//n:선물 개수  x:총 선물 만드는데 걸리는 최대 시간   
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	int start = 1;
	int end = n;
	int mid = 0;
	while (start <= end) {
		priority_queue<int, vector<int>, greater<int>>pq;
		mid = (start + end) / 2;  //공장 개수
		bool flag = true;

		for (int i = 0; i < mid; i++) {
			pq.push(0);   //공장에 선물만드는데 0시간 설정
		}

		for (int i = 0; i < n; i++) { //선물들 탐색
			int choice = pq.top(); //가장 적은 시간인 공장 선택
			pq.pop();
			if (choice + v[i] > x) { //x 만드는 시간 초과하면
				flag = false;
			}
			pq.push(choice + v[i]); //v[i]선물 만드는시간 추가하여 넣는다.
		}

		if (flag == false) { //만드는 시간 초과하면
			start = mid + 1;
		}
		else end = mid - 1;
	}

	cout << mid << '\n';

	return 0;
}
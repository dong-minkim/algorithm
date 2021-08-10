#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n, x;
vector<int> v;

int main()
{
	//n:���� ����  x:�� ���� ����µ� �ɸ��� �ִ� �ð�   
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
		mid = (start + end) / 2;  //���� ����
		bool flag = true;

		for (int i = 0; i < mid; i++) {
			pq.push(0);   //���忡 ��������µ� 0�ð� ����
		}

		for (int i = 0; i < n; i++) { //������ Ž��
			int choice = pq.top(); //���� ���� �ð��� ���� ����
			pq.pop();
			if (choice + v[i] > x) { //x ����� �ð� �ʰ��ϸ�
				flag = false;
			}
			pq.push(choice + v[i]); //v[i]���� ����½ð� �߰��Ͽ� �ִ´�.
		}

		if (flag == false) { //����� �ð� �ʰ��ϸ�
			start = mid + 1;
		}
		else end = mid - 1;
	}

	cout << mid << '\n';

	return 0;
}
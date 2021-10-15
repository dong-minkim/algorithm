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

vector<int> arr;
vector<int> arr2;
vector<int> Answer;
int n;

bool champion(int x) {

	int idx = x;
	int tmp = arr[x];

	//왼쪽으로 일단 탐색, 같은 수를 처리하기 위한 방법
	while (0 <= idx - 1 && arr[idx - 1] < tmp) {
		tmp++;
		idx--;
	}
	if (idx != 0)
		return false;

	idx = x;
	//오른쪽으로 처리
	while (idx + 1 < n && tmp > arr[idx + 1]) {
		tmp++;
		idx++;
	}
	if (idx != n - 1)
		return false;
	
	return true;
}

int main() {
	FAST_IO;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);

		//챔피언 후보들
		if (i == 0 || arr[i] > arr[i - 1]) {
			arr2.push_back(i);
		}
	}

	int left = 0;
	int right = arr2.size() - 1;

	if (champion(arr2[left])) {
		for (int i = 0; i < arr2.size(); i++) {
			cout << arr2[i] + 1 << " ";
		}
	}
	else if (!champion(arr2[right])) {
		cout << -1 << '\n';
	}
	else {
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			if (champion(arr2[mid])) {
				right = mid;
			}
			else left = mid;
		}

		for (int i = 0; i < arr2.size(); i++) {
			if (arr2[i] >= arr2[right]) {
				cout << arr2[i] + 1 << " ";
			}
		}
	}
	

	
	return 0;
}
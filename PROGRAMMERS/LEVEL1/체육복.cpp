#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int arr[30];
    for (int i = 0; i < n; i++) { arr[i] = 1; }
    for (int i = 0; i < lost.size(); i++) { arr[lost[i] - 1]--; }
    for (int i = 0; i < reserve.size(); i++) { arr[reserve[i] - 1]++; }

    for (int i = 0; i < n; i++) {
        if (arr[i] == 2 && arr[i - 1] == 0 && i >= 1) {
            arr[i]--;
            arr[i - 1]++;
        }
        if (arr[i] == 2 && arr[i + 1] == 0 && i < n) {
            arr[i]--;
            arr[i + 1]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) answer++;
    }

    return answer;
}
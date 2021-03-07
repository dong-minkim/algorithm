#include <string>
#include <vector>

using namespace std;
int arr[1000001] = { 0, };

//효율성을 위해 에라토스테네스의 체 사용
int solution(int n) {
    int answer = 0;
    for (int i = 2; i * i <= n; i++) {
        if (arr[i] == 1) continue;
        for (int j = i * i; j <= n; j += i) {
            arr[j] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) answer++;
    }

    return answer;
}
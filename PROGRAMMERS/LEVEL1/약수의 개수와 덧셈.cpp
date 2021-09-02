#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (pow((int)sqrt(i), 2) == i) {
            answer -= i;
        }
        else answer += i;
    }

    return answer;
}
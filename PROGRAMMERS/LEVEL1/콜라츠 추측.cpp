#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long number = num;
    if (number == 1) return 0;
    while (answer <= 500) {

        if (number % 2 == 0) number /= 2;
        else number = number * 3 + 1;

        answer++;

        if (number == 1) {
            return answer;
        }
    }
    answer = -1;
    return answer;
}
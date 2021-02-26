#include <string>
#include <vector>

using namespace std;
string solution(int a, int b) {
    string answer[] = { "THU","FRI","SAT","SUN","MON","TUE","WED" };
    int sum = 0;
    for (int i = 1; i < a; i++) {
        if (i < 8) {
            if (i % 2 != 0) { sum += 31; }
            else if (i == 2) { sum += 29; }
            else { sum += 30; }
        }
        else {
            if (i % 2 == 0) sum += 31;
            else sum += 30;
        }
    }
    sum += b;
    return answer[sum % 7];
}
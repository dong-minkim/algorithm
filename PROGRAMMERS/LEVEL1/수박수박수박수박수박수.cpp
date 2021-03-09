#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int i = n / 2;
    while (i--) {
        answer += "¼ö¹Ú";
    }
    if (n % 2 == 1) {
        answer += "¼ö";
    }
    return answer;
}
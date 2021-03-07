#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    //-도 숫자로 바꾸어 음수처리 시킬수 있다.
    answer = stoi(s);
    return answer;
}
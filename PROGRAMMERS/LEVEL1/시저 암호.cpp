#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    char c = ' ';
    char tmp = ' ';
    for (int i = 0; i < s.length(); i++) {

        if ('a' <= s[i] && s[i] <= 'z') {
            tmp = 'a';
        }
        else if ('A' <= s[i] && s[i] <= 'Z') {
            tmp = 'A';
        }
        if (s[i] != ' ') {
            c = tmp + (s[i] - tmp + n) % 26;

        }
        else if (s[i] == 32) c = 32;

        answer.push_back(c);
    }
    return answer;
}
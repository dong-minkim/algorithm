#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int j = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            j = 1;
            continue;
        }
        if (j % 2 == 1) {
            if ('a' <= s[i] && s[i] <= 'z') {
                s[i] = toupper(s[i]);
            }
        }
        else {
            if ('A' <= s[i] && s[i] <= 'Z') {
                s[i] = tolower(s[i]);
            }
        }
        j++;

    }
    answer = s;
    return answer;
}
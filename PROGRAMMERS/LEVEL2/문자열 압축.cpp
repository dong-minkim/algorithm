#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.length();
    for (int i = 1; i <= s.length() / 2; i++) {
        string tmp = "";

        for (int j = 0; j < s.length(); j += i) {
            if (j + 2 * i <= s.length()) {
                if (s.substr(j, i) != s.substr(j + i, i)) {
                    tmp += s.substr(j, i);
                    continue;
                }
                tmp += s.substr(j, i);
                int cnt = 1;
                while (j + 2 * i <= s.length() && s.substr(j, i) == s.substr(j + i, i)) {
                    cnt++;
                    j += i;
                }
                tmp += to_string(cnt);
            }
            else {
                tmp += s.substr(j);
                break;
            }
        }
        if (answer > tmp.size())answer = tmp.size();
    }
    return answer;
}
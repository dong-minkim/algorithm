#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    //sort(s.begin(),s.end(),greater<char>()); 대치가능
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    answer = s;
    return answer;
}
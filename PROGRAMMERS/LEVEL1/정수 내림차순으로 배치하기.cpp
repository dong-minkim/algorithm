#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string s;
    s = to_string(n);
    sort(s.begin(), s.end(), greater<>());
    answer = stoll(s);
    return answer;
}
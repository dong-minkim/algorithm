#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> v;
    while (n) {
        v.push_back(n % 3);
        n /= 3;
    }
    int j = 1;
    int m = v.size();
    for (int i = 0; i < m; i++) {
        answer += v.back() * j;
        v.pop_back();
        j *= 3;
    }
    return answer;
}
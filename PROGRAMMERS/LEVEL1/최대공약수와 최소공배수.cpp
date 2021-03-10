#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    else {
        return gcd(b, a % b);
    }
}
vector<int> solution(int n, int m) {
    vector<int> answer;
    int num = gcd(n, m);
    answer.push_back(num);
    answer.push_back(n * m / num);
    return answer;
}
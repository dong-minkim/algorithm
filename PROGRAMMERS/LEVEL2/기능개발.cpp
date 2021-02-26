#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> tmp;
    int cnt = 0;
    for (int i = 0; i < progresses.size(); i++) {
        int num = (99 - progresses[i]) / speeds[i] + 1;
        tmp.push_back(num);
    }
    int j;
    for (int i = 0; i < tmp.size(); i++) {
        cnt = 0;
        for (j = i; j < tmp.size(); j++) {
            if (tmp[i] >= tmp[j]) {
                cnt++;
            }
            else {
                i = j - 1;
                break;
            }
        }
        answer.push_back(cnt);
        if (cnt == tmp.size() || j == tmp.size()) break;
    }
    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (lottos[i] == win_nums[j]) {
                cnt1++;
                cnt2++;
            }
        }
        if (lottos[i] == 0) cnt2++;
    }

    int result = 7 - cnt2;
    if (result >= 6) result = 6;
    answer.push_back(result);

    result = 7 - cnt1;
    if (result >= 6) result = 6;
    answer.push_back(result);

    return answer;
}
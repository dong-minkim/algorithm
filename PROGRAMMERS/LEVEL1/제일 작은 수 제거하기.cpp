#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min_ = 987654;
    if (arr.size() == 1) {
        answer.push_back(-1);
        return answer;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (min_ > arr[i]) min_ = arr[i];
    }

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == min_) continue;
        answer.push_back(arr[i]);
    }

    return answer;
}
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    answer.resize(arr1.size());
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr1[0].size(); j++) {
            int num = arr1[i][j] + arr2[i][j];
            answer[i].push_back(num);
        }
    }

    return answer;
}
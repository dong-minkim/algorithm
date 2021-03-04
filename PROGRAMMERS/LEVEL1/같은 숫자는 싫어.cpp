#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    answer.push_back(arr.back());
    arr.pop_back();
    while (!arr.empty()) {
        if (arr.back() != answer.back()) {
            answer.push_back(arr.back());
        }
        arr.pop_back();
    }
    reverse(answer.begin(), answer.end());
    return answer;
}
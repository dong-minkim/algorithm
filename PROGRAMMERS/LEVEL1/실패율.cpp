#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int arr[501] = { 0, };

bool cmp(pair<double, int>& a, pair<double, int>& b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int total = stages.size();
    vector<pair<double, int>> v;

    vector<int> result;

    for (int i = 0; i < stages.size(); i++) {
        arr[stages[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        if (total == 0) v.push_back({ 0,i });
        else {
            v.push_back({ (double)arr[i] / total, i });
            total -= arr[i];
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        result.push_back(v[i].second);
    }

    return result;
}
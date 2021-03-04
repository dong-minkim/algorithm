#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < scoville.size(); i++) {
        q.push(scoville[i]);
    }
    while (q.top() < K && q.size() > 1) {
        int first = q.top();
        q.pop();
        int second = q.top();
        q.pop();
        q.push(first + 2 * second);
        answer++;

    }
    if (q.top() < K)return -1;


    return answer;
}
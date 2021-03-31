#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int sum = 0;
    sort(d.begin(), d.end());
    if (d[answer] > budget) return 0;
    while (1) {
        sum += d[answer];
        if (answer == d.size() - 1 || (sum + d[answer + 1]) > budget) break;
        answer++;
    }
    answer++;
    return answer;
}
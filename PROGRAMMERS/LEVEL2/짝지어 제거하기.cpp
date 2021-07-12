#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> v;

int solution(string s)
{
    int answer = -1;

    v.push_back(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == v.back()) v.pop_back();
        else v.push_back(s[i]);
    }

    if (v.empty()) answer = 1;
    else answer = 0;

    return answer;
}
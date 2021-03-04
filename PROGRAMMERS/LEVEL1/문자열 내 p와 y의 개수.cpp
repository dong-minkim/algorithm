#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int num_1 = 0;
    int num_2 = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P') num_1++;
        if (s[i] == 'y' || s[i] == 'Y') num_2++;
    }
    if (num_1 != num_2) answer = false;

    return answer;
}
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
string number = "";
vector<long long> num;
vector<char> oper;
char arr[3] = { '*','+','-' };


long long solution(string expression) {
    long long answer = 0;

    for (int i = 0; i < expression.size(); i++) {
        if (!(expression[i] == '+' || expression[i] == '*' || expression[i] == '-')) {
            number += expression[i];
        }
        else {
            num.push_back(stoi(number));
            oper.push_back(expression[i]);
            number = "";
        }
    }
    num.push_back(stoi(number));

    do {
        vector<long long> copy_num = num;
        vector<char> copy_oper = oper;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < copy_oper.size(); j++) {
                if (copy_oper[j] == arr[i]) {
                    if (copy_oper[j] == '+') copy_num[j] = copy_num[j] + copy_num[j + 1];
                    else if (copy_oper[j] == '-') copy_num[j] = copy_num[j] - copy_num[j + 1];
                    else if (copy_oper[j] == '*') copy_num[j] = copy_num[j] * copy_num[j + 1];

                    copy_num.erase(copy_num.begin() + j + 1);
                    copy_oper.erase(copy_oper.begin() + j);
                    j--;
                }
            }
        }
        answer = max(answer, abs(copy_num[0]));

    } while (next_permutation(arr, arr + 3));


    return answer;
}
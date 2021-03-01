#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int index = 0;
    vector<int> result;
    for (int i = 0; i < dartResult.length(); i++) {
        if (dartResult[i] == 'S') {

        }
        else if (dartResult[i] == 'D') {
            result[index - 1] = pow(result[index - 1], 2);
        }
        else if (dartResult[i] == 'T') {
            result[index - 1] = pow(result[index - 1], 3);
        }
        else if (dartResult[i] == '*') {
            result[result.size() - 1] *= 2;
            if (result.size() > 1) {
                result[result.size() - 2] *= 2;
            }
        }
        else if (dartResult[i] == '#') {
            result[result.size() - 1] *= (-1);
        }
        else if (dartResult[i + 1] == '0') {
            result.push_back(10);
            index++;
            i++;
        }
        else {
            result.push_back(dartResult[i] - '0');
            index++;
        }
    }
    for (int i = 0; i < result.size(); i++) {
        answer += result[i];

    }
    return answer;
}
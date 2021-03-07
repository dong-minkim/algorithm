#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;
int left_d = 0;
int right_d = 0;
int left_h = 10;
int right_h = 12;
int left_tmp = 0;
int right_tmp = 0;
string solution(vector<int> numbers, string hand) {
    string answer = "";
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            left_h = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            right_h = numbers[i];
        }
        else {
            if (numbers[i] == 0) { numbers[i] = 11; }

            left_tmp = abs(left_h - numbers[i]);
            right_tmp = abs(right_h - numbers[i]);

            left_d = (left_tmp / 3) + (left_tmp % 3);
            right_d = (right_tmp / 3) + (right_tmp % 3);

            if (left_d == right_d) {
                if (hand == "left") {
                    answer += "L";
                    left_h = numbers[i];
                }
                else {
                    answer += "R";
                    right_h = numbers[i];
                }
            }
            else if (left_d < right_d) {
                answer += "L";
                left_h = numbers[i];
            }
            else {
                answer += "R";
                right_h = numbers[i];
            }
        }
    }
    return answer;
}
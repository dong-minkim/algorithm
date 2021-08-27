#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int Answer = 0;
    for (int i = 0; i < absolutes.size(); i++) {
        if (signs[i] == false) {
            Answer -= absolutes[i];
        }
        else Answer += absolutes[i];
    }

    return Answer;
}
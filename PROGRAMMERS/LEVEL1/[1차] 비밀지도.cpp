#include <string>
#include <vector>

using namespace std;


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string st;
    for (int i = 0; i < n; i++) {
        int num = arr1[i] | arr2[i];
        st = "";
        for (int j = 0; j < n; j++) {
            if (num % 2 == 0) st = " " + st;
            else st = "#" + st;
            num /= 2;
        }
        answer.push_back(st);
    }

    return answer;
}
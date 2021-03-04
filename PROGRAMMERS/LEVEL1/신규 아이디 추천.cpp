#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    //1단계
    for (int i = 0; i < new_id.length(); i++) {
        if ('A' <= new_id[i] && new_id[i] <= 'Z') {
            new_id[i] = tolower(new_id[i]);
        }
    }
    //2단계 - 주의
    for (int i = 0; i < new_id.length();) {
        if (('a' <= new_id[i] && new_id[i] <= 'z') ||
            ('0' <= new_id[i] && new_id[i] <= '9') ||
            new_id[i] == '-' || new_id[i] == '_' ||
            new_id[i] == '.') {
            i++;
        }
        else {
            new_id.erase(new_id.begin() + i);
        }
    }
    //3단계
    for (int i = 1; i < new_id.length();) {
        if (new_id[i] == '.' && new_id[i - 1] == '.') {
            new_id.erase(new_id.begin() + i);
        }
        else i++;
    }
    //4단계
    if (new_id.front() == '.') new_id.erase(new_id.begin(), new_id.begin() + 1);
    if (new_id.back() == '.') new_id.erase(new_id.end() - 1, new_id.end());
    //5단계
    if (new_id.empty() == true) new_id = "a";
    //6단계
    if (new_id.length() >= 16) {
        new_id.erase(15);
    }
    if (new_id.back() == '.') new_id.erase(new_id.end() - 1, new_id.end());

    //7단계
    if (new_id.length() <= 2) {
        while (new_id.length() != 3) {
            new_id += new_id.back();
        }
    }

    return new_id;
}
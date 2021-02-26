#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }
    sort(answer.begin(), answer.end());
    //unique : 연속된 중복 원소를 vector의 제일 뒷 부분에 쓰레기 값으로 보내버린다.
    //unique가 끝났을때 반환되는 값은 vector의 쓰레기 값의 첫번째 위치
    //erase: 지운다.
    answer.erase(unique(answer.begin(), answer.end()), answer.end());
    return answer;
}
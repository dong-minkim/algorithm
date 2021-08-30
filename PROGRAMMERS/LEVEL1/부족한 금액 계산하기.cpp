using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;

    for (int i = 0; i < count; i++) {
        answer += (i + 1) * price;
    }

    long long result = answer - money;

    if (result >= 0) answer = result;
    else answer = 0;

    return answer;
}
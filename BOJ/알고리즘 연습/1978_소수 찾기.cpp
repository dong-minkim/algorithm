#include<iostream>
#include<cmath>
using namespace std;

int primeNumber(int num);
int main()
{
    int cnt = 0;
    int testcase;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        int x;
        cin >> x;
        if (primeNumber(x)) cnt++;
    }

    cout << cnt;
    return 0;
}
int primeNumber(int num)
{
    if (num == 1) return false;
    if (num == 2) return true;     //num이 2인 경우 소수이므로 true
    else if (num % 2 == 0) return false; //num이 짝수인 경우 소수가 아니므로 소수가 아니므로 false
    int i = 3;
    while (i <= sqrt(num)) {
        if (num % i == 0) {
            return false;
        }
        else i += 2;
    }
    return true;
}
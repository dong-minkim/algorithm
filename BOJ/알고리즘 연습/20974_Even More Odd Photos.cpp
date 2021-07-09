#include <iostream>
using namespace std;

int N;
int even = 0;
int odd = 0;
int cnt = 0;
int ans = 0;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (num % 2 == 0) even++;
        else odd++;
    }

    while (1)
    {
        if (even >= 1)
        {
            even--;
            cnt++;
        }
        else
        {
            if (odd >= 2)
            {
                odd -= 2;
                cnt++;
            }
            else break;
        }
        if (odd == 5 && even == 0)
        {
            odd -= 3;
            cnt++;
        }
        else
        {
            if (odd >= 1)
            {
                odd--;
                cnt++;
            }
            else break;
        }
    }
    cout << cnt;
}
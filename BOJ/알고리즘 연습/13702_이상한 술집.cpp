#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<long long> v;

long long n, k;
long long l, mid, cnt, ans=0,r=0;
int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        long long num;
        cin >> num;
        v.push_back(num);
        r = max(r, num);
    }
    l = 1;
    while (l <= r)
    {
        cnt = 0;
        mid = (l + r) / 2;
        for (int i = 0; i < n; i++)
            cnt += v[i] / mid;
        if (cnt >= k)
        {
            ans = max(ans, mid);
            l = mid + 1;
        }
        else //cnt가 작을 때
            r = mid - 1;
    }
    cout << ans << '\n';
}

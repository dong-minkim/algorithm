#include <iostream>
#include <algorithm>
using namespace std;

unsigned long long arr[1001][3];

int main() {

    int N;
    int color[3];
    arr[0][0] = 0;
    arr[0][1] = 0;
    arr[0][2] = 0;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> color[0] >> color[1] >> color[2];
        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + color[0];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + color[1];
        arr[i][2] = min(arr[i - 1][1], arr[i - 1][0]) + color[2];
    }
    cout << min(arr[N][2], min(arr[N][0], arr[N][1]));

    return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#define MAX 2100000000
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int N;
int board[16][16];
int cost[16];
int bit = 0;
int P;
int on = 0;
int anw = MAX;
int dp[66000];

int count(int n) {
    int ret = 0;
    for (int i = 1; i < 1 << N; i = i << 1) {
        if (i & n) ret += 1;
    }
    return ret;
}

int main(void) {

    FAST_IO;

    cin >> N;
    for (int i = 0; i < 66000; i++) {
        dp[i] = MAX;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int n; cin >> n;
            board[i][j] = n;
        }
    }
    int on = 0;
    for (int i = 0; i < N; i++) {
        char c; cin >> c;
        if (c == 'Y') {
            on++;
            bit = bit | (1 << i);
        }
    }
    dp[bit] = 0;
    cin >> P;
    for (int i = 0; i < (1 << N); i++) {
        if (dp[i] == MAX) continue;
        for (int j = 0; j < N; j++) {
            if ((1 << j) & i) continue;
            for (int k = 0; k < N; k++) {
                if (((1 << k) & i) == 0) continue;
                dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + board[k][j]);
            }
        }
        if (count(i) >= P) {
            if (anw > dp[i]) anw = dp[i];
        }
    }
    if (bit == 0 && P != 0) anw = -1;
    cout << anw << endl;
    return 0;
}
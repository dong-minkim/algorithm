#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int n, t;

string Answer;


int main()
{
    int T, test_case;
    string B;
    cin >> T;
    for (test_case = 0; test_case < T; test_case++)
    {

        cin >> n >> t;
        cin >> B;

        string A(n, '0');
        for (int i = 0; i < n; i++) {
            if (i <= t - 1) {
                if (i + t < n) {
                    A[i + t] = B[i];
                }
            }
            else if (i > n - t - 1) {
                if (i - t >= 0) {
                    A[i - t] = B[i];
                }
            }
            else {
                if ((i + 2 * t) <= n - 1 && B[i + (2 * t)] == '0') {
                    if (i - t >= 0) {
                        A[i - t] = B[i];
                    }
                }
                else {
                    if ((i + t) < n && (i - t) >= 0) {
                        if (A[i - t] == '1')   A[i + t] = '0';
                        else A[i + t] = B[i];
                    }
                }
            }

        }

        cout << "Case #" << test_case + 1 << endl;
        cout << A << endl;
    }

    return 0;
}
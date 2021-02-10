#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int test;
    cin >> test;
    int arr[51];
    for (int i = 0; i < test; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + test);
    int result = arr[0] * arr[test - 1];
    cout << result;

    return 0;

}
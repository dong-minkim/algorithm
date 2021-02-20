#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool check(vector<int> sub) {
    bool flag = true;
    for (int i = 0; i < sub.size(); i++) {
        if (sub[i] != 1) {
            flag = false;
            break;
        }
    }
    return flag;

}
void clear(vector<int> sub) {
    for (int i = 0; i < sub.size(); i++) {
        sub[i] = 0;
    }
}
void print(vector<int> sub) {
    for (int i = 0; i < sub.size(); i++) {
        cout << sub[i] << "  ";
    }
    cout << endl;
}
int main()
{
    int len = 0, max = 0;
    vector<int> v;
    vector<int> sub;
    cin >> len >> max;
    for (int i = 0; i < max; i++) {
        sub.push_back(0);
    }
    int temp = 0;
    for (int i = 0; i < len; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    int ans = 0;

    //뒤에서 부터 1,2,3,4,5 묶음으로 끊는다.
    for (int i = len - 1; i >= 0; i--) {
       
        if (check(sub)) {
            for (int j = 0; j < sub.size(); j++) {
                sub[j] = 0;
            }
            ans++;
            i++;
        }
        else {
            sub[v[i] - 1] = 1;
        }
    }
    if (check(sub)) { ans++; }
    cout << ans + 1 << endl;
}
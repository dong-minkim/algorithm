#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int tmp;
bool cmp(string a, string b) {
    if (a[tmp] != b[tmp]) return a[tmp] < b[tmp];
    else return a < b;
}
vector<string> solution(vector<string> strings, int n) {

    tmp = n;
    sort(strings.begin(), strings.end(), cmp);
    return strings;
}

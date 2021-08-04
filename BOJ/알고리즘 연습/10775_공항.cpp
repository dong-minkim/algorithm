#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int parent[100001];

int g, p;
int cnt = 0;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a); 
    b = find(b);
    parent[b] = a;
}

int main() {

    cin >> g >> p;


    for (int i = 0; i <= g; i++) parent[i] = i;

    
    
    while (p--) {

        int num;
        cin >> num;

        int docking = find(num);

        if (docking != 0) { //²ËÂ÷Áö ¾ÊÀ¸¸é
            cnt++;
            merge(docking-1, docking);
        }
        //²Ë Ã¡´Ù
        else {
            cout << "hello<<'\n";
            break;
        }
    }

    cout << cnt << '\n';

    return 0;
}

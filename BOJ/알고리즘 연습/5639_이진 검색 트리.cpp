#include<iostream>
#include<vector>

using namespace std;


vector<pair<int, int>> tree;

int root;
int num;

void Input() {
    tree.resize(10001, { 0,0 });
    cin >> root;
    while (cin>>num) {
        int node = root;
        while (1) {
            if (node < num) {
                if (tree[node].second != 0) { //오른쪽에 자식이 없으면
                    node = tree[node].second;
                }
                else { //자식 있으면
                    tree[node].second = num;
                    break;
                }
            }
            else { 
                if (tree[node].first != 0) { //왼쪽에 자식없으면
                    node = tree[node].first;
                }
                else {
                    tree[node].first = num;
                    break;
                }
            }
        }
    }
}

void postOrder(int node) {
    if (tree[node].first != 0) {
        postOrder(tree[node].first);
    }
    if (tree[node].second != 0) {
        postOrder(tree[node].second);
    }
    cout << node << '\n';
}

int main() {

    Input();
    postOrder(root);

    //입력을 끝났다고 표기하기위해 ctrl+z 누르면된다.
    return 0;
}

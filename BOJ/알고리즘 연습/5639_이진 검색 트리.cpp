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
                if (tree[node].second != 0) { //�����ʿ� �ڽ��� ������
                    node = tree[node].second;
                }
                else { //�ڽ� ������
                    tree[node].second = num;
                    break;
                }
            }
            else { 
                if (tree[node].first != 0) { //���ʿ� �ڽľ�����
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

    //�Է��� �����ٰ� ǥ���ϱ����� ctrl+z ������ȴ�.
    return 0;
}

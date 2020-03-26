#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct _root {
    int data;
    _root *left, *right;
};
int n;
const int maxn = 30 + 5;

int post[maxn], inord[maxn];

_root *head = new _root;

_root* build(int pl, int pr, int il, int ir) {
    _root* root = new _root;
    root -> data = post[pr];
    if(root -> data == post[n - 1]) head = root;
    root -> left = root -> right = NULL;
    int temp = find(inord + il, inord + ir + 1, post[pr]) - inord - il;
    //printf("pl = %d, pr = %d, il = %d, ir = %d, root = %d, 相对位置为%d\n", pl, pr, il, ir, post[pr], temp);
    //system("pause");
    if(temp > 0)
        root -> left = build(pl, pl + temp - 1, il, il + temp - 1);
    if(pl + temp <= pr - 1)
        root -> right = build(pl + temp, pr - 1, il + temp + 1, ir);
    return root;
}

queue <_root*> que;
queue <int> ans;

void print(_root *root) {
    if(root == NULL) return;
    que.push(root);
    while(!que.empty()) {
        _root * now = que.front();
        que.pop();
        ans.push(now -> data);
        if(now -> left) que.push(now -> left);
        if(now -> right) que.push(now -> right);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i ++) cin >> post[i];
    for(int i = 0; i < n; i ++) cin >> inord[i];
    build(0, n - 1, 0, n - 1);
    print(head);
    cout << ans.front();
    ans.pop();
    while(!ans.empty()) {
        cout << ' ' << ans.front();
        ans.pop();
    }
    cout << endl;
    return 0;
}

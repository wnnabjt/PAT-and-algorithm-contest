#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Tree {
    int data, l, r, pre;
} tree[10];

vector <int> vec_level, vec_in;

void level(int root) {
    queue <int> que;
    que.push(root);
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        if(now == -1) continue;
        vec_level.push_back(now);
        que.push(tree[now].r);
        que.push(tree[now].l);
    }
}

void in(int root) {
    if(root == -1) return;
    in(tree[root].r);
    vec_in.push_back(root);
    in(tree[root].l);
}

int main() {
    int n;
    char c1, c2;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        tree[i].pre = -1;
    }
    for(int i = 0; i < n; i ++) {
        cin >> c1 >> c2;
        tree[i].data = i;
        if(c1 != '-') {
            tree[i].l = c1 - '0';
            tree[c1 - '0'].pre = i;
        } else {
            tree[i].l = -1;
        }
        if(c2 != '-') {
            tree[i].r = c2 - '0';
            tree[c2 - '0'].pre = i;
        } else tree[i].r = -1;
    }
    int root = 0;
    while(~tree[root].pre) {
        root = tree[root].pre;
    }
    level(root);
    in(root);
    for(int i = 0; i < vec_level.size(); i ++) {
        if(i) cout << " ";
        cout << vec_level[i];
    }
    cout << endl;
    for(int i = 0; i < vec_in.size(); i ++) {
        if(i) cout << " ";
        cout << vec_in[i];
    }
    cout << endl;
    return 0;
}
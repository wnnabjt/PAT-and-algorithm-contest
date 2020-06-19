/*
    Push的顺序为前序遍历，Pop的顺序为中序遍历，所以这道题就是
    已知前序遍历和中序遍历求后序遍历。
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

vector <int> pre, in, post;

typedef struct Tree {
    int data;
    Tree *l, *r;
} *ptree;

ptree build(int pl, int pr, int il, int ir) {
    if(pl > pr || il > ir) return NULL;
    int pos;
    for(int i = il; i <= ir; i ++) {
        if(in[i] == pre[pl]) {
            pos = i;
            break;
        }
    }
    ptree root = new Tree;
    root -> data = in[pos];
    root -> l = root -> r = NULL;
    root -> l = build(pl + 1, pl + pos - il, il, pos - 1);
    root -> r = build(pl + pos - il + 1, pr, pos + 1, ir);
    return root;
}

void post_order(ptree root) {
    if(!root) return;
    post_order(root -> l);
    post_order(root -> r);
    post.push_back(root -> data);
}

int main() {
    string op;
    int n, num;
    cin >> n;
    stack <int> s;
    pre.push_back(-1);
    in.push_back(-1);
    for(int i = 0; i < 2 * n; i ++) {
        cin >> op;
        if(op == "Push") {
            cin >> num;
            pre.push_back(num);
            s.push(num);
        } else {
            in.push_back(s.top());
            s.pop();
        }
    }
    post_order(build(1, n, 1, n));
    for(int i = 0; i < post.size(); i ++) {
        if(i) cout << " ";
        cout << post[i];
    }
    cout << endl;
    return 0;
}
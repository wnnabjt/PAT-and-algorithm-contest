#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct Tree {
    int data;
    Tree *l, *r;
} *root;
typedef Tree* ptree;

int n, lc, rc;

vector <int> ans;

typedef pair <int, int> pii;

pii vec[100 + 5];

void level(ptree &root) {
    queue <ptree> que;
    root = new Tree;
    root -> data = 0;
    root -> l = root -> r = NULL;
    que.push(root);
    while(!que.empty()) {
        ptree now = que.front(), temp;
        int k = now -> data;
        que.pop();
        lc = vec[k].first, rc = vec[k].second;
        if(~lc) {
            temp = new Tree;
            temp -> data = lc;
            temp -> l = temp -> r = NULL;
            now -> l = temp;
            que.push(temp);
        }
        if(~rc) {
            temp = new Tree;
            temp -> data = rc;
            temp -> l = temp -> r = NULL;
            now -> r = temp;
            que.push(temp);
        }
    }
}

int val[100 + 5];

int cnt;

void inorder(ptree &root) {
    if(root == NULL) {
        return;
    }
    inorder(root -> l);
    root -> data = val[cnt ++];
    inorder(root -> r);
}

void levelorder(ptree root) {
    if(root == NULL) return;
    queue <ptree> que;
    que.push(root);
    while(!que.empty()) {
        ptree now = que.front();
        que.pop();
        ans.push_back(now -> data);
        if(now -> l) que.push(now -> l);
        if(now -> r) que.push(now -> r);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d %d", &lc, &rc);
        vec[i] = make_pair(lc, rc);
    }
    level(root);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &val[i]);
    }
    sort(val, val + n);
    inorder(root);
    levelorder(root);
    for(int i = 0; i < ans.size(); i ++) {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
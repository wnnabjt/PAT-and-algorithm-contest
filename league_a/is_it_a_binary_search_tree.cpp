#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;


struct Node {
    int num;
    Node *l, *r;
};

void build(Node * &root, int num) {
    if(root == NULL) {
        root = new Node;
        root -> num = num;
        root -> l = root -> r = NULL;
        return;
    } else if(root -> num <= num) {
        build(root -> r, num);
    } else build(root -> l, num);
}

vector <int> pre, pre_mirror, vec, post, post_mirror;

void Preorder(Node * root) {
    if(root == NULL) return;
    pre.push_back(root -> num);
    Preorder(root -> l);
    Preorder(root -> r);
}

void Preorder_mirror(Node * root) {
    if(root == NULL) return;
    pre_mirror.push_back(root -> num);
    Preorder_mirror(root -> r);
    Preorder_mirror(root -> l);
}

void Postorder(Node * root) {
    if(root == NULL) return;
    Postorder(root -> l);
    Postorder(root -> r);
    post.push_back(root -> num);
}

void Postorder_mirror(Node * root) {
    if(root == NULL) return;
    Postorder_mirror(root -> r);
    Postorder_mirror(root -> l);
    post_mirror.push_back(root -> num);
}

int main() {
    int n, num;
    cin >> n;
    Node * root = NULL;
    for(int i = 0; i < n; i ++) {
        cin >> num;
        vec.push_back(num);
        build(root, num);
    }
    Preorder(root);
    Preorder_mirror(root);
    Postorder(root);
    Postorder_mirror(root);
    if(pre == vec) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i ++) {
            if(i) cout << ' ';
            cout << post[i];
        }
    } else if(pre_mirror == vec) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i ++) {
            if(i) cout << ' ';
            cout << post_mirror[i];
        }
    } else cout << "NO";
    cout << endl;
    return 0;
}
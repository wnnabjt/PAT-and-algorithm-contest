#include <cstdio>
#include <cstring>
#include <windows.h>
using namespace std;

struct Tree {
    int data;
    Tree *l, *r, *pre;
};

typedef Tree * ptree;

ptree real;

void right_rotary(ptree &root) {
    ptree &pre = root -> pre, &prepre = pre -> pre;
    ptree temp = pre;
    if(prepre != NULL) {
        if(prepre -> l == pre) {
            prepre -> l = root;
        } else {
            prepre -> r = root;
        }
    }
    root -> r = temp;
    pre -> l = NULL;
    pre -> pre = root;
}

void left_rotary(ptree &root) {
    ptree &pre = root -> pre, &prepre = pre -> pre;
    ptree temp = pre;
    if(prepre != NULL) {
        if(prepre -> r == pre) {
            prepre -> r = root;
        } else {
            prepre -> l = root;
        }
    }
    root -> l = temp;
    pre -> r = NULL;
    pre -> pre = root;
}

void avl_insert(ptree &root, ptree &pre, int num, int flag) {
    if(root == NULL) {
        root = new Tree;
        root -> pre = pre;
        root -> data = num;
        root -> l = NULL;
        root -> r = NULL;
        if(flag == 1) {
            if(pre -> pre) {
                if(pre -> pre -> r == NULL) {
                    right_rotary(pre);
                } else if(pre -> pre -> l == NULL) {
                    right_rotary(pre);
                    left_rotary(root);
                }
            }
        } else if(flag == 2) {
            if(pre -> pre) {
                if(pre -> pre -> l == NULL) {
                    left_rotary(pre);
                } else if(pre -> pre -> r == NULL) {
                    left_rotary(pre);
                    right_rotary(root);
                }
            }
        }
        real = root;
    } else {
        if(num < root -> data) {
            avl_insert(root -> l, root, num, 1);
        } else {
            avl_insert(root -> r, root, num, 2);
        }
    }
}

void print(ptree root) {
    if(root == NULL) return;
    printf("%d\t", root -> data);
    print(root -> l);
    print(root -> r);
}

int main() {
    int n, num;
    scanf("%d", &n);
    ptree root = NULL, pre = NULL;
    while(n --) {
        scanf("%d", &num);
        avl_insert(root, pre, num, 0);
    }
    while(real -> pre) {
        real = real -> pre;
    }
    printf("%d\n", real -> data);
    print(root);
    return 0;
}
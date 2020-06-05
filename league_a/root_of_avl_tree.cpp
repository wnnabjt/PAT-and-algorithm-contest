#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

struct Tree {
    int data, high;
    Tree *l, *r;
} *root;

int max(int a, int b) {
    return a > b ? a : b;
}

typedef Tree * ptree;

int get_high(ptree root) {
    if(root == NULL) return 0;
    else return root -> high;
}

void update_high(ptree root) {
    root -> high = max(get_high(root -> l), get_high(root -> r)) + 1;
}

int balance_factor(ptree root) {
    return get_high(root -> l) - get_high(root -> r);
}

void left_rotary(ptree &root) {
    ptree temp = root -> r;
    root -> r = temp -> l;
    temp -> l = root;
    update_high(root);
    update_high(temp);
    root = temp;
}

//右旋：root做root的左儿子的右儿子，那么如果root的左儿子原本就有右儿子，需要把他变为root的左儿子。然后再将root变为他的左儿子的右儿子，记得更新这两颗子树的高度，还要将这两颗子树的
//根节点变为root的左儿子

void right_rotary(ptree &root) {
    ptree temp = root -> l;
    root -> l = temp -> r;
    temp -> r = root;
    update_high(root);
    update_high(temp);
    root = temp;
}

void avl_insert(ptree &root, int num) {
    if(root == NULL) {//叶子节点，设定叶子节点高度为1
        root = new Tree;
        root -> data = num;
        root -> high = 1;
        root -> l = root -> r = NULL;
    } else {
        if(num < root -> data) {
            avl_insert(root -> l, num);
            update_high(root);//在root的子树中插入新元素需要重新调整这个树的高度
            if(balance_factor(root) == 2) {//在root的子树中插入新元素后需要检查树是否平衡
                if(balance_factor(root -> l) == 1) {//如果root的左子树高度为1，则说明需要右旋
                    right_rotary(root);
                } else if(balance_factor(root -> l) == -1) {//如果root的左子树比右子树低，则需要先左旋再右旋
                    left_rotary(root -> l);
                    right_rotary(root);
                } 
            }
        } else {
            avl_insert(root -> r, num);
            update_high(root);
            if(balance_factor(root) == -2) {//如果是插入到root的右子树的话，那么root的右子树比左子树高2才需要调整
                if(balance_factor(root -> r) == -1) {
                    left_rotary(root);
                } else if(balance_factor(root -> r) == 1) {
                    right_rotary(root -> r);
                    left_rotary(root);
                }
            }
        }
    }
}

int main() {
    int n, num;
    scanf("%d", &n);
    while(n --) {
        scanf("%d", &num);
        avl_insert(root, num);
    }
    printf("%d\n", root -> data);
    return 0;
}
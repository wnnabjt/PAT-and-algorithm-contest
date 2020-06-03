/*
    本题大意：要求模拟一个栈，实现包含压栈和弹栈操作，以及求出栈中元素的中位数的操作。
    题目显示数据范围1e5, 访问次数1e5，但是如果对栈中元素排序，复杂度为O(n * nlgn)。
    就会超时，因此我们想到其他方法，我一开始想到的是二叉搜索树，因为二叉搜索树的
    前序遍历结果就是从小到大，我们找到那个中位数是轻而易举的，且复杂度为O(nlgn)，但是
    写完之后发现超时了，原因应该是树的深度过深了，所以需要平衡搜索数才能ac。
    这里我说另一种解法。由于是要找一组数中的中位数，而且查询有可能有很多次，因此
    我们想到，如果用一个数组将前面出现的所有数字出现的次数保存下来，查询中位数
    就很方便，但是由于这些数字是随着栈的弹出弹入随时变化的，因此我们想到用树状数组
    或者线段树来维护某一区间内出现数字的个数，刚好数据范围也是1e5，正和题意，那么开搞。
*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#define mid ((l + r) >> 1)
using namespace std;

const int maxn = 1e5 + 5;

int segment_tree[maxn << 2];

int n, op;
string operation;
vector <int> vec;

string pop = "Pop", push = "Push", median = "PeekMedian";

void push_up(int k) {
    segment_tree[k] = segment_tree[k << 1 | 1] + segment_tree[k << 1];
}

void update(int k, int l, int r, int num, int c) {
    if(l == r) {
        segment_tree[k] += c;
        return;
    }
    if(num <= mid) update(k << 1, l, mid, num, c);
    else update(k << 1 | 1, mid + 1, r, num, c);
    push_up(k);
}

int ans;

int query(int k, int l, int r, int num) {
    if(l == r) return l;
    if(segment_tree[k << 1] >= num) return query(k << 1, l, mid, num);
    else return query(k << 1 | 1, mid + 1, r, num - segment_tree[k << 1]);
}

int main() {
    cin >> n;
    while(n --) {
        cin >> operation;
        if(operation == push) {
            cin >> op;
            update(1, 1, 1e5, op, 1);
            vec.push_back(op);
        } else if(operation == pop) {
            if(vec.size()) {
                update(1, 1, 1e5, vec.back(), -1);
                cout << vec.back() << endl;
                vec.pop_back();
            } else cout << "Invalid" << endl;
        } else if(operation == median) {
            if(vec.size()) {
                cout << query(1, 1, 1e5, (vec.size() + 1) / 2) << endl;
            } else cout << "Invalid" << endl;
        }
    }
    return 0;
}
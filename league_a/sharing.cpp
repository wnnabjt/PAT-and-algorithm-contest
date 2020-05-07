#include <iostream>
#include <cstring>
#include <string>
using namespace std;

const int maxn = 1000000 + 5, maxm = 100000 + 5;

struct Edge {
    int to, next;
    char c;
};

int head[maxn];
int cnt;

void init() {
    memset(head, -1, sizeof head);
    cnt = 0;
}

int main() {
    
    return 0;
}
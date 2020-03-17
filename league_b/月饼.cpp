#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;

struct foods{
    int w, p;
    double wp;
} food[maxn];

bool cmp(foods a, foods b) {
    return a.wp > b.wp;
}

int main() {
    int n, d, w, p;
    while(cin >> n >> d) {
        for(int i = 0; i < n; i ++) cin >> food[i].w;
        for(int i = 0; i < n; i ++) cin >> food[i].p;
        for(int i = 0; i < n; i ++) food[i].wp = food[i].p * 1.0 / food[i].w;
        double sum = 0.0;
        sort(food, food + n, cmp);
        for(int i = 0; i < n; i ++) {
            if(d >= food[i].w) {
                d -= food[i].w;
                sum += food[i].p;
            } else {
                sum += d * food[i].wp;
                break;
            }
        }
        printf("%.2f\n", sum);
    }
    return 0;
}

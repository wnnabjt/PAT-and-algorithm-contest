#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;
struct Cakes {
    double tot;
    double price;
    double tot_price;
} cakes[maxn];

bool cmp(Cakes a, Cakes b) {
    return a.price > b.price;
}

int main() {
    int n, m;
    double temp;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i ++) {
        scanf("%lf", &cakes[i].tot);
    }
    for(int i = 0; i < n; i ++) {
        scanf("%lf", &temp);
        cakes[i].tot_price = temp;
        cakes[i].price = temp / cakes[i].tot;
    }
    sort(cakes, cakes + n, cmp);
    double sum = 0.0;
    for(int i = 0; i < n; i ++) {
        if(m >= cakes[i].tot) {
            sum += cakes[i].tot_price;
            m -= cakes[i].tot;
        } else {
            sum += m * cakes[i].price;
            break;
        }
    }
    printf("%.2f\n", sum);
    return 0;
}
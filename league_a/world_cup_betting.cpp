#include <cstdio>
#include <algorithm>
using namespace std;

double a[3][3];

char s[4] = "WTL";

int main() {
    for(int i = 0; i < 3; i ++) {
        for(int j = 0; j < 3; j ++) {
            scanf("%lf", &a[i][j]);
        }
    }
    double sum = 1;
    for(int i = 0; i < 3; i ++) {
        sum *= *max_element(a[i], a[i] + 3);
        printf("%c ", s[max_element(a[i], a[i] + 3) - a[i]]);
    }
    printf("%.2f", (sum * 0.65 - 1) * 2);
    return 0;
}

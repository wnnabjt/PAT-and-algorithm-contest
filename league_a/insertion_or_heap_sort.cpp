#include <cstdio>
using namespace std;

const int maxn = 100 + 5;
int val[maxn], sorted[maxn];

void swap(int a, int b) {
    int t = val[a];
    val[a] = val[b];
    val[b] = t;
}

void sink(int n, int i) {
    int max = i;
    int l = i << 1, r = i << 1 | 1;
    if(l <= n && val[l] > val[max]) max = l;
    if(r <= n && val[r] > val[max]) max = r;
    if(max != i) {
        swap(max, i);
        sink(n, max);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &val[i]);
    }
    for(int i = 1; i <= n; i ++) {
        scanf("%d", &sorted[i]);
    }
    int i, j;
    for(i = 1; i < n && sorted[i] <= sorted[i + 1]; i ++);
    for(j = i + 1; j <= n && sorted[j] == val[j]; j ++);
    if(j == n + 1) {
        printf("Insertion Sort\n");
        int k, temp = sorted[i + 1];
        for(k = i; k >= 1 && sorted[k] >= temp; k --) {
            sorted[k + 1] = sorted[k];
        }
        sorted[k + 1] = temp;
        for(int i = 1; i <= n; i ++) val[i] = sorted[i];
    } else {
        printf("Heap Sort\n");
        for(int i = n / 2; i >= 1; i --) {
            sink(n, i);
        }
        bool flag;
        for(int i = n; i > 1; i --) {
            flag = true;
            for(int j = 1; j <= n; j ++) {
                if(val[j] != sorted[j]) {
                    flag = false;
                    break;
                }
            }
            swap(1, i);
            sink(i - 1, 1);
            if(flag) break;
        }
    }
    for(int i = 1; i <= n; i ++) {
        if(i != 1) {
            printf(" ");
        }
        printf("%d", val[i]);
    }
    printf("\n");
    return 0;
}
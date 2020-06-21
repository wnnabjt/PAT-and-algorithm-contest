#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
int val[maxn];
int sorted[maxn];
int n;

void insert(int k) {
    sort(sorted, sorted + k + 2);
    for(int i = 0; i < n; i ++) {
        val[i] = sorted[i];
    }
}

void merge() {
    int k = 1;
    bool flag = true;
    while(flag) {
        flag = false;
        for(int i = 0; i < n; i ++) {
            if(val[i] != sorted[i]) {
                flag = true;;
            }
        }
        k = k * 2;
        for(int i = 0; i < n / k; i ++) {
            sort(val + i * k, val + (i + 1) * k);
        }
        sort(val + n / k * k, val + n);
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &val[i]);
    }
    for(int i = 0; i < n; i ++) {
        scanf("%d", &sorted[i]);
    }
    int k, j;
    for(k = 0; k < n - 1 && sorted[k] <= sorted[k + 1]; k ++);
    for(j = k + 1; j < n && val[j] == sorted[j]; j ++);
    if(j == n) {
        printf("Insertion Sort\n");
        insert(k);
    } else {
        printf("Merge Sort\n");
        merge();
   }
   for(int i = 0; i < n; i ++) {
        if(i) printf(" ");
        printf("%d", val[i]);
    }
    printf("\n");
    return 0;
}
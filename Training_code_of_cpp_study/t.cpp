#include <stdio.h>
#include <algorithm>

int arr[100];

int main() {
    freopen("data.txt", "r", stdin);
    freopen("result.txt", "w", stdout);
    int num = 0;
    while(~scanf("%d", &arr[num ++]));
    num -= 1;
    std::sort(arr, arr + num);
    for(int i = 0; i < num; i ++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}
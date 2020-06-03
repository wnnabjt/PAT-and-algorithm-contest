#include <cstdio>
#include <map>
using namespace std;

map <int, int> mp;

int main() {
    int n, m;
    int temp;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            scanf("%d", &temp);
            mp[temp] ++;
        }
    }
    map <int, int> :: iterator i;
    int max = 0;
    int ans;
    for(i = mp.begin(); i != mp.end(); i ++) {
        if(i -> second > max) {
            ans = i -> first;
            max = i -> second;
        }
    }
    printf("%d\n", ans);
    return 0;
}
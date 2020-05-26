#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e4 + 5;

int vis[maxn];

vector <int> vec;

int main() {
    int n, temp;
    cin >> n;
    for(int i = 0; i < n; i ++) {
        cin >> temp;
        vis[temp] ++;
        vec.push_back(temp);
    }
    for(int i = 0; i < n; i ++) {
        if(vis[vec[i]] == 1) {
            printf("%d\n", vec[i]);
            break;
        }
        if(i != n - 1)  continue;
        printf("None\n");
    }
    return 0;
}
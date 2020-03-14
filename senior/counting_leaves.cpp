#include <iostream>
#include <vector>
using namespace std;

const int maxn = 100 + 5;
vector <int> edges[maxn];

int n, m;

void addedge(int u, int v) {
    edges[u].push_back(v);
}

int layer, layers[maxn];
int _max;

void dfs(int u) {
    _max = max(_max, layer);
    if(edges[u].size() == 0) {
        layers[layer] ++;
        return;
    }
    for(int k = 0; k < edges[u].size(); k ++) {
        int v = edges[u][k];
        layer ++;
        dfs(v);
        layer --;
    }
}

int main() {
    while(cin >> n >> m && n) {
        int id, k, child;
        while(m --) {
            cin >> id >> k;
            while(k -- > 0) {
                cin >> child;
                addedge(id, child);
            }
        }
        dfs(1);
        if(edges[1].size()) {
            cout << '0';
            for(int i = 1; i <= _max; i ++) {
                cout << ' ' << layers[i];
            }
        } else cout << '1';
        cout << endl;
        for(int i = 0; i < maxn; i ++) edges[i].clear();
        for(int i = 0; i < maxn; i ++) layers[i] = 0;
        layer = 0;
        _max = 0;
    }
    return 0;
}

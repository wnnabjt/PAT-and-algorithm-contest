#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1000 + 5;

vector <int> mice, players, temp;
int _rank[maxn];

int main() {
    int np, ng, a;
    memset(_rank, -1, sizeof _rank);
    scanf("%d %d", &np, &ng);
    for(int i = 0; i < np; i ++) {
        scanf("%d", &a);
        mice.push_back(a);
    }
    for(int i = 0; i < np; i ++) {
        scanf("%d", &a);
        players.push_back(a);
    }
    int Max, k;
    int tot_rank = 0;
    int pre = 0, now;
    while(players.size() > 1) {
        pre = -1;
        k = 0, Max = 0;
        for(int i = 0; i < players.size(); i ++) {
            if(mice[players[i]] > Max) {
                Max = mice[players[i]];
                k = players[i];
            }
            if(i % ng == ng - 1 || i == players.size() - 1) {
                temp.push_back(k);
                for(int j = pre + 1; j <= i; j ++) {
                    if(players[j] != k) {
                        if(_rank[players[j]] == -1)
                            _rank[players[j]] = ceil(players.size() * 1.0 / ng) + 1;
                    }
                }
                Max = 0;
                k = 0;
                pre = i;
            }
        }
        players = temp;
        temp.clear();
        tot_rank ++;
    }
    _rank[players[0]] = 1;
    for(int i = 0; i < np; i ++) {
        if(i) printf(" ");
        printf("%d", _rank[i]);
    }
    return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 10000 + 5;

struct User {
    int score, perfectly_solved, id;
    int solved[6];
    bool is_solved;
    bool submit[6];
} users[maxn];

int full_score[6];
int _rank[maxn];

bool cmp(const User a, const User b) {
    if(a.score == b.score) {
        if(a.perfectly_solved == b.perfectly_solved) {
            return a.id < b.id;
        } else return a.perfectly_solved > b.perfectly_solved;
    } else return a.score > b.score;
}

int main() {
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    for(int i = 1; i <= k; i ++) {
        scanf("%d", &full_score[i]);
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= k; j ++) {
            users[i].solved[j] = -1;
        }
    }
    int id, idx, score;
    while(m --) {
        scanf("%d %d %d", &id, &idx, &score);
        if(score > users[id].solved[idx]) {
            users[id].is_solved = true;
            users[id].id = id;
            if(users[id].solved[idx] > 0) {
                users[id].score -= users[id].solved[idx];
            }
            users[id].score += score;
            users[id].solved[idx] = score;
            if(score == full_score[idx]) {
                users[id].perfectly_solved += 1;
            }
        } else users[id].submit[idx] = true;
    }
    sort(users + 1, users + n + 1, cmp);
    int cnt = 1;
    _rank[users[1].id] = 1;
    for(int i = 2; i <= n; i ++) {
        if(users[i].score != users[i - 1].score) cnt = i;
        _rank[users[i].id] = cnt;
    }
    for(int i = 1; i <= n; i ++) {
        User temp = users[i];
        if(temp.is_solved) {
            printf("%d %05d %d", _rank[temp.id], temp.id, temp.score);
            for(int i = 1; i <= k; i ++) {
                if(temp.solved[i] != -1) printf(" %d", temp.solved[i]);
                else if(temp.submit[i]) printf(" 0");
                else printf(" -");
            }
            printf("\n");
        }
    }
    return 0;
}
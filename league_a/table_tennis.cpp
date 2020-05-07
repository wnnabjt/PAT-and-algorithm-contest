/*
    本题大意：共有n个可用的桌子，当有一对运动员到来时，如果有桌子是可用的，
    则选取桌子编号最小的那个桌子比赛，否则他们将加入一个队列。
    你的任务是计算每组运队员在队列中等待时间以及每个桌子招待的组数。
    一些关于vip问题使这个程序变得复杂： ①，当一个vip桌子可用，队列中第一
    组vip使用该桌子。②，队列中没有vip时，vip桌子可以被!vip使用。
    ③，如果有一对vip到了，但是并没有可用的vip桌子，那么vip可以使用普通桌子。

    input:
        n(运动员组数)
        1 ~ n 每个运动员的到达时间  比赛时间  是否会员标志位
        k(number of players) m(number of vip)
        1 ~ m vip桌子的编号
    
    output:
        首先按照服务时间序输出参赛运动员的信息，包括 到达时间 服务时间 等待时间 
        如若有一队未在关店时间之前参加比赛，则不输出其信息。
        然后在一行输出每张桌子的服务人数。


    本题思路：将所有players按照到达时间序排序，把所有vip_players按照到达
    时间序排序。遍历所有桌子，寻找第一个服务结束且编号最靠前的桌子，如果该桌子
    为!vip桌子，则服务目前第一对players，如果为vip桌子，则服务第一对vip_players
    ，如果无vip则服务第一对players。
*/

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Players {
    int hours, minutes, seconds, last_time, is_vip, wait_time, id;
    int s_hours, s_minutes, s_seconds;
};

vector <Players> all_players, vip_players;

const int maxn = 100 + 5, maxm = 10000 + 5, inf = 0x3f3f3f3f;

bool table[maxn];
bool vis[maxm];
int num[maxn];
int end_time[maxn];

bool cmp(const Players a, const Players b) {
    return a.hours * 3600 + a.minutes * 60 + a.seconds < b.hours * 3600 + b.minutes * 60 + b.seconds;
}

int Time(const Players a) {
    return a.hours * 3600 + a.minutes * 60 + a.seconds;
}

int main() {
    for(int i = 1; i < maxn; i ++) {
        end_time[i] = 8 * 60 * 60;
    }
    int n, h, m, s, last_time, flag_vip;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) {
        scanf("%d:%d:%d %d %d", &h, &m, &s, &last_time, &flag_vip);
        if(last_time > 120) last_time = 120;
        all_players.push_back(Players{h, m, s, last_time, flag_vip, 0, i, 0, 0, 0});
        if(flag_vip) vip_players.push_back(Players{h, m, s, last_time, flag_vip, 0, i, 0, 0, 0});
    }
    int K, M, vip_table;
    scanf("%d %d", &K, &M);
    for(int i = 0; i < M; i ++) {
        scanf("%d", &vip_table);
        table[vip_table] = true;
    }
    sort(all_players.begin(), all_players.end(), cmp);
    sort(vip_players.begin(), vip_players.end(), cmp);
    int pos_all = 0, pos_vip = 0;
    while(true) {
        if(pos_all >= n) break;
        int k = 0, min_elem = inf;
        for(int i = 1; i <= K; i ++) {
            if(min_elem > end_time[i]) {
                min_elem = end_time[i];
                k = i;
            }
        }
        // printf("is vip ? %d\n", table[k]);
        // printf("The first is %d -> %d:%d:%d\n", k, min_elem / 3600, min_elem % 3600 / 60, min_elem % 3600 % 60);
        if(min_elem >= 21 * 3600) break;
        if(Time(vip_players[pos_vip]) <= min_elem && table[k]) { //队列中有vip，且最先好的桌子是vip桌子
            if(vis[vip_players[pos_vip].id]) {
                pos_vip++;
                continue;
            }
            vis[vip_players[pos_vip].id] = true;
            // printf("It's be true %d\n", vis[vip_players[pos_vip].id]);
            Players &temp = vip_players[pos_vip];
            num[k] ++;
            int T = Time(vip_players[pos_vip]);
            end_time[k] = max(T, min_elem) + temp.last_time * 60;
            temp.s_hours = max(T, min_elem) / 3600;
            temp.s_minutes = (max(T, min_elem) % 3600) / 60;
            temp.s_seconds = (max(T, min_elem) % 3600) % 60;
            if(T < min_elem) {
                temp.wait_time = (min_elem - T) / 60;
                if((min_elem - T) % 3600 % 60 >= 30) temp.wait_time ++;
            }
            pos_vip ++;
            end_time[k] = max(T, min_elem) + temp.last_time * 60;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",temp.hours, temp.minutes, temp.seconds, temp.s_hours, temp.s_minutes, temp.s_seconds, temp.wait_time);
        } else {
            if(vis[all_players[pos_all].id]) {
                pos_all ++;
                continue;
            }
            vis[all_players[pos_all].id] = true;
            // printf("It's be true %d\n", vis[all_players[pos_all].id]);
            Players &temp = all_players[pos_all];
            num[k] ++;
            int T = Time(all_players[pos_all]);
            end_time[k] = max(T, min_elem) + temp.last_time * 60;
            temp.s_hours = max(T, min_elem) / 3600;
            temp.s_minutes = (max(T, min_elem) % 3600) / 60;
            temp.s_seconds = (max(T, min_elem) % 3600) % 60;
            if(T < min_elem) {
                temp.wait_time = (min_elem - T) / 60;
                if((min_elem - T) % 3600 % 60 >= 30) temp.wait_time ++;
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",temp.hours, temp.minutes, temp.seconds, temp.s_hours, temp.s_minutes, temp.s_seconds, temp.wait_time);
            pos_all ++;
        }
    }
    for(int i = 1; i <= K; i ++) {
        if(i > 1) printf(" ");
        printf("%d", num[i]);
    }
    return 0;
}
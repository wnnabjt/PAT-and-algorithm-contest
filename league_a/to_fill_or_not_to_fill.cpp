#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

const int maxn = 30000 + 5, inf = 0x3f3f3f3f;
double price[maxn];

int main() {
    int cmax, distance, davg, n, d;
    double p;
    scanf("%d %d %d %d", &cmax, &distance, &davg, &n);
    for(int i = 0; i < maxn; i ++) price[i] = inf * 1.0;
    for(int i = 0; i < n; i ++) {
        scanf("%lf %d", &p, &d);
        price[d] = p;
    }
    int now_position = 0;
    double now_gas = 0, tot_cost = 0;
    bool flag, flag1 = false;
    if(price[0] + 1 > inf) {
        printf("The maximum travel distance = 0.00\n");
    }
    else {
        while(true) {
            if(now_position >= distance) break;
            flag = false;
            // printf("Now is %d range is %d you is %.2f\n", now_position, now_position + cmax * davg, now_gas);
            for(int i = now_position + 1; i <= now_position + cmax * davg && i <= distance; i ++) {
                if(price[i] <= price[now_position] || i == distance) {
                    flag = true;
                    // printf("now is %d Find smaller %d\n", now_position, i);
                    if(now_gas * davg >= i - now_position) {
                        // printf("gas is enough %.2f -> %.2f\n", now_gas, now_gas * 1.0 - (i - now_position) * 1.0 / davg * 1.0);
                        now_gas -= (i - now_position) * 1.0 / davg;
                        now_position = i;
                        break;
                    } else {
                        tot_cost += (((i - now_position - now_gas * davg) * 1.0 / davg) * price[now_position]);
                        // printf("Cost %.2f\n", ((i - now_position - now_gas * davg) / davg) * price[now_position]);
                        now_position = i;
                        now_gas = 0;
                        break;
                    }
                }
            }
            if(!flag) {
                for(int i = now_position + 1; i <= now_position + cmax * davg && i <= distance; i ++) {
                    if(price[i] + 1 < inf || i == distance) {
                        if(now_position + cmax * davg <= distance)
                            tot_cost += (cmax - now_gas) * 1.0 * price[now_position];
                        else {
                            if(now_position + now_gas * davg >= distance) {
                                now_position = i;
                            } else {
                                tot_cost += ((distance - now_position) * 1.0 / davg - now_gas) * price[now_position];
                                now_position = distance;
                            }
                            flag = true;
                            break;
                        }
                        // printf("i is %d\n", i);
                        // printf("cost is %.2f\n", (cmax - now_gas) * 1.0 * price[now_position]);
                        // printf("now is %d you %.2f\n", now_position, cmax * 1.0 - now_gas);
                        now_gas = cmax - (i - now_position) * 1.0 / davg;
                        now_position = i;
                        flag = true;
                        break;
                    }
                }
            }
            if(!flag) {
                if(now_position + davg * cmax >= distance) {
                    if(now_gas < (distance - now_position) * 1.0 / davg) {
                        tot_cost += ((distance - now_position) * 1.0 / davg - now_gas) * price[now_position];
                    }
                    break;
                }
            }
            if(!flag) {
                double ans = now_position += cmax * 1.0 * davg;
                printf("The maximum travel distance = %.2f\n", ans);
                flag1 = true;
                break;
            }
            // printf("\n");
        }
        if(!flag1) printf("%.2f\n", tot_cost);
    }
    return 0;
}
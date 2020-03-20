#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Cus {
    int time, cost;
};
vector <Cus> VCus;

bool cmp(Cus a, Cus b) {
    return a.time < b.time;
}

int add[105];

int main() {
    int n, k, h, m, s, time, sum = 0, av;
    scanf("%d %d", &n, &k);
    av = n;
    for(int i = 0; i < n; i ++) {
        scanf("%d:%d:%d %d", &h, &m, &s, &time);
        VCus.push_back(Cus{h * 3600 + m * 60 + s, time * 60});
    }
    sort(VCus.begin(), VCus.end(), cmp);
    int temp;
    for(int i = 0; i < n; i ++) {
        if(i < k) {
            if(VCus[i].time < 8 * 3600) {
                sum += (8 * 3600 - VCus[i].time);
                add[i] = 8 * 3600 + VCus[i].cost;
            } else if(VCus[i].time <= 17 * 3600){
                add[i] = VCus[i].time + VCus[i].cost;
            } else av --;
        } else {
            if(VCus[i].time <= 17 * 3600) {
                temp = min_element(add, add + k) - add;
                if(VCus[i].time < add[temp]) sum += (add[temp] - VCus[i].time);
                add[temp] = max(VCus[i].time, add[temp]) + VCus[i].cost;
            } else av --;
        }
    }
    double mi = 0;
    mi += sum / 60;
    mi += (sum % 60) * 1.0 / 60;
    printf("%.1f\n", mi / av);
    return 0;
}

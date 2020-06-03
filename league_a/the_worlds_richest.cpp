#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100000 + 5;

struct Peo {
    string name;
    int wealth;
    int age;
};
vector <Peo> peo, vaild;

bool cmp(Peo a, Peo b) {
    if(a.wealth == b.wealth) {
        if(a.age == b.age) {
            return a.name < b.name;
        }
        return a.age < b.age;
    }
    return a.wealth > b.wealth;
}

int wealth_num[205];

int main() {
    int n, k, _case = 0;
    scanf("%d %d", &n, &k);
    string name;
    int age, wealth;
    name.resize(10);
    for(int i = 0; i < n; i ++) {
        scanf("%s %d %d", &name[0], &age, &wealth);
        peo.push_back(Peo{name, wealth, age});
    }
    
    int m, l, r;
    Peo temp;
    sort(peo.begin(), peo.end(), cmp);
    for(int i = 0; i < n; i ++) {
        temp = peo[i];
        if(wealth_num[temp.age] ++ < 100) {
            vaild.push_back(temp);
        }
    }
    while(k --) {
        scanf("%d %d %d", &m, &l, &r);
        int num = 0;
        printf("Case #%d:\n", ++_case);
        for(int i = 0; i < vaild.size(); i ++) {
            if(num == m) break;
            if(vaild[i].age >= l && vaild[i].age <= r) {
                num ++;
                printf("%s %d %d\n", vaild[i].name.c_str(), vaild[i].age, vaild[i].wealth);
            }
        }
        if(num == 0) printf("None\n");
    }
    return 0;
}
#include <iostream>
#include <map>
using namespace std;

map <int, double> mp;


const int maxn = 1000 + 5;

int a1[maxn], a2[maxn];
double b1[maxn], b2[maxn];

int main() {
    int k1, k2;
    cin >> k1;
    for(int i = 0; i < k1; i ++) {
        cin >> a1[i] >> b1[i];
    }
    cin >> k2;
    for(int i = 0; i < k2; i ++) {
        cin >> a2[i] >> b2[i];
    }
    int a3;
    double b3;
    for(int i = 0; i < k1; i ++) {
        for(int j = 0; j < k2; j ++) {
            a3 = a1[i] + a2[j];
            b3 = b1[i] * b2[j];
            if(b3 != 0.0)
                mp[a3] += b3;
        }
    }
    map<int, double> :: reverse_iterator i; // 反向迭代器
    for(i = mp.rbegin(); i!= mp.rend(); i ++) {
        if(i -> second == 0) mp.erase(i -> first); //删除值为零的元素，通过key删除
    }
    printf("%d", mp.size());
    for(i = mp.rbegin(); i != mp.rend(); i ++) {
        printf(" %d %.1f", i -> first, i -> second);
    }
    printf("\n");
    return 0;
}

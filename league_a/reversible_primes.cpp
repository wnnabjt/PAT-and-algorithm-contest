#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const int maxn = 100 + 5;
int bit[maxn];

bool isprime(int num) {
    if(num < 2) return false;
    for(int i = 2; i <= sqrt(num); i ++) {
        if(!(num % i)) return false;
    }
    return true;
}

int main() {
    int d, cnt, n;
    while(cin >> n >> d && n >= 0) {
        if(isprime(n)) {
            cnt = 0;
            while(n) {
                bit[cnt ++] = n % d;
                n /= d;
            }
            for(int i = cnt - 1; i >= 0; i --) n += bit[i] * pow(d, cnt - 1 -i);
            if(isprime(n)) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else cout << "No" << endl;
    }
    return 0;
}
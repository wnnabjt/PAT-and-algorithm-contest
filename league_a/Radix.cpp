/*
    ������⣺��������������Ƶ����֣������жϽ����Ƕ�ת��Ϊʮ���ƺ��Ƿ���ȡ�
    ע������һ�����ֺ����Ľ����Ѿ���������һ����ֻ������ĳ�ֽ����µı��룬��
    ��������������С��������ʹ��������������ʮ��������ȡ�

    ˼·����Ŀ����2 ~ 36 ��ʵ��һ���ӣ��𰸽������п��ܳ��󣬵��䷶Χ��
    (��������������� + 1����֪���� + 1)�����Χ�ڣ�֪����Χ������Сֵ
    ����ֱ�Ӷ��ִ𰸾����ˡ�
*/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#define mid ((l + r) >> 1)
using namespace std;

typedef long long ll;

ll inf = 8e18;

string s1, s2;
ll n1, n2;

ll quickly_pow(ll a, int b) {
    ll ans = 1;
    while(b) {
        if(b & 1) {
            ans *= a;
        }
        a *= a;
        b >>= 1;
    }
    return ans;
}

ll get_decimal(string s, ll radix) {
    ll ans = 0;
    int len = s.size();
    for(int i = len - 1; i >= 0; i --) {
        if(s[i] > '9') ans += (s[i] - 'a' + 10) * quickly_pow(radix, len - i - 1);
        else ans += (s[i] - '0') * quickly_pow(radix, len - i - 1);
        if(ans > n1 || ans < 0) return n1 + 1;
    }
    return ans;
}

int main() {
    int tag, radix;
    while(cin >> s1 >> s2 >> tag >> radix) {
        n1 = inf;
        if(tag == 2) swap(s1, s2);
        n1 = get_decimal(s1, radix);
        char c = *max_element(s2.begin(), s2.end());
        ll l = c < '9' ? (c - '0' + 1) : (c - 'a' + 11), r = n1 + 1, ans = inf, temp;
        while(l <= r) {
            temp = get_decimal(s2, mid);
            if(temp > n1) r = mid - 1;
            else if(temp < n1) l = mid + 1;
            else {
                ans = min(ans, mid);
                r = mid - 1;
            }
        }
        if(ans == inf) cout << "Impossible" << endl;
        else cout << ans << endl;
    }
    return 0;
}

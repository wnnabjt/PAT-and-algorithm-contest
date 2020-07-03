#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <sstream>
using namespace std;

const int maxn = 100 + 5;
char s[maxn];

int main() {
    int n;
    scanf("%d", &n);
    int cnt = 0, point = 0;
    double sum = 0, num = 0;
    bool flag1, flag2, flag;
    for(int i = 0; i < n; i ++) {
        scanf("%s", s);
        flag1 = flag2 = false;
        flag = true;
        int len = strlen(s);
        point = 0;
        for(int i = 0; i < len; i ++) {
            if(i == 0 && s[i] == '-') {
                if(flag1) {
                    flag = false;
                    break;
                }
                flag1 = true;
                continue;
            }
            if(s[i] == '.') {
                if(flag2) {
                    flag = false;
                    break;
                }
                flag2 = true;
                point = i;
                continue;
            }
            if(!isdigit(s[i])) {
                flag = false;
                break;
            }
        }
        if(point && len - point > 3) flag = false;
        if(flag) {
            stringstream ss;
            ss << s;
            double temp;
            ss >> temp;
            if(temp > 1000 || temp < -1000) {
                printf("ERROR: %s is not a legal number\n", s);
                continue;
            }
            cnt ++;
            sum += temp;
        } else {
            printf("ERROR: %s is not a legal number\n", s);
        }
    }
    if(cnt == 0) {
        printf("The average of 0 numbers is Undefined\n");
    } else if(cnt == 1) {
        printf("The average of 1 number is %.2f\n", sum);
    } else {
        printf("The average of %d numbers is %.2f\n", cnt, sum / cnt);
    }
    return 0;
}
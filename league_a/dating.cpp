#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool vis[30];

string weeke[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string s1, s2, s3, s4;
    int cnt = 0;
    cin >> s1 >> s2 >> s3 >> s4;
    string week;
    int hours, minutes;
    for(int i = 0; i < min(s1.size(), s2.size()); i ++) {
        if(cnt == 0) {
            if(s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
                cnt ++;
                week = weeke[s1[i] - 'A'];
            }
        } else if(cnt == 1) {
            if(s1[i] == s2[i]) {
                if(s1[i] >= 'A' && s1[i] <= 'N') {
                    hours = 10 + s1[i] - 'A';
                    cnt ++;
                } else if(isdigit(s1[i])) {
                    hours = s1[i] - '0';
                    cnt ++;
                }
            }
        } else break;
    }
    for(int i = 0; i < min(s3.size(), s4.size()); i ++) {
        if(s3[i] == s4[i] && isalpha(s3[i])) {
            minutes = i;
            break;
        }
    }
    printf("%s %02d:%02d\n", week.c_str(), hours, minutes);
    return 0;
}
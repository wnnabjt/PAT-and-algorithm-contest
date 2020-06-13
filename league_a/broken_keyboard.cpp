#include <string>
#include <iostream>
#include <cctype>
using namespace std;

const int maxn = 200 + 5;

bool vis[maxn];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s2.size(); i ++) {
        vis[s2[i]] = true;
    }
    for(int i = 0; i < s1.size(); i ++) {
        if(!vis[s1[i]]) {
            vis[s1[i]] = true;
            if(isupper(s1[i])) vis[s1[i] - 'A' + 'a'] = true;
            if(islower(s1[i])) vis[s1[i] - 'a' + 'A'] = true;
            if(isdigit(s1[i]) || s1[i] == '_' || isupper(s1[i])) {
                printf("%c", s1[i]);
            } else printf("%c", s1[i] - 'a' + 'A');
        }
    }
    printf("\n");
    return 0;
}
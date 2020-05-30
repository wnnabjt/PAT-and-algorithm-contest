#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map <int, vector <string> > mp;

int main() {
    int n, k;
    string name;
    int c, num;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i ++) {
        name.resize(5);
        scanf("%s", &name[0]);
        scanf("%d", &c);
        for(int i = 0; i < c; i ++) {
            scanf("%d", &num);
            mp[num].push_back(name);
        }
    }
    map <int, vector <string> > :: iterator i;
    int low = 0;
    for(i = mp.begin(); i != mp.end(); i ++) {
        while(low + 1 != i -> first) {
            printf("%d 0\n", ++ low);
        }
        printf("%d %d\n", i -> first, i -> second.size());
        sort(i -> second.begin(), i -> second.end());
        for(int j = 0; j < i -> second.size(); j ++) {
            printf("%s\n", i -> second[j].c_str());
        }
        low ++;
    }
    return 0;
}
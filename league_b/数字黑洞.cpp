#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

bool cmp(char a, char b) {
    return a > b;
}

int main() {
    string s, out = "6174", temp1, temp2;
    int n1, n2, n;
    cin >> s;
    while(s.length() < 4) {
        s += "0";
    }
    temp1 = s;
    sort(temp1.begin(), temp1.end(), cmp);
    n1 = stoi(temp1);
    if(temp1[0] == temp1[3]) printf("%04d - %04d = %04d\n", n1, n1, 0);
    else
        do {
            temp1 = s;
            temp2 = s;
            sort(temp1.begin(), temp1.end(), cmp);
            sort(temp2.begin(), temp2.end());
            n2 = stoi(temp2);
            n1 = stoi(temp1);
        	n = n1 - n2;
            s = to_string(n);
            printf("%04d - %04d = %04d\n", n1, n2, n);
        } while(s != out);
    return 0;
}

/*
    要求：
        n1 = n3 = max
        n2 >= 3
        n1 + n2 + n3 - 2 == n
        n2 >= n1
        2n1 + n2 == n + 2
        n1 <= (n + 2) / 3
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int len = s.size();
    int n1 = (len + 2) / 3, n2 = len + 2 - 2 * n1;
    for(int i = 0; i < n1 - 1; i ++) {
        cout << s[i];
        for(int i = 0; i < n2 - 2; i ++) {
            cout << ' ';
        }
        cout << s[len - 1 - i] << endl;
    }
    for(int i = n1 - 1; i < n1 + n2 - 1; i ++) {
        cout << s[i];
    }
    cout << endl;
    return 0;
}
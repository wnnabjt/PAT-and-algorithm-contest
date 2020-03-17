/*
    A除以B：本题是较大的数除以一个较小的数，模拟小学除法。。。或者 java python
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> ans;

int main() {
    string A;
    int B;
    cin >> A >> B;
    int now = 0, tot = A.length() - 1, C = A[0] - '0';
    while(now <= tot) {
        if(C >= B) {
            ans.push_back(C / B);
            C = C % B;
        } else {
            now ++;
            C = C * 10 + A[now] - '0';
            ans.push_back(C / B);
            C = C % B;
        }
        if(now == tot) break;
    }
    vector <int> :: iterator i;
    for(i = ans.begin(); i != ans.end(); i ++)
        cout << *i;
    cout << ' ' << C << endl;
    return 0;
}

#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int main() {
    string A, B;
    char DA, DB;
    cin >> A >> DA >> B >> DB;
    int SA = 0, SB = 0;
    for(int i = 0; i < A.size(); i ++) {
        if(A[i] == DA) SA ++;
    }
    for(int i = 0; i < B.size(); i ++) {
        if(B[i] == DB) SB ++;
    }
    ll na = DA - '0', nb = DB - '0';
    while(-- SA) {
        if(na == DA - '0' && SA == -1) {
            na = 0;
            break;
        }
        na = na * 10 + DA - '0';
    }
    while(-- SB) {
        if(nb == DB - '0' && SB == -1) {
            nb = 0;
            break;
        }
        nb = nb * 10 + DB - '0';
    }
    cout << na + nb << endl;
    return 0;
}

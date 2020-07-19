#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    while(n --) {
        cin >> s;
        int num1 = 0, num2 = 0;
        for(int i = 0; i < s.size(); i ++) {
            if(i < s.size() / 2) {
                num1 = num1 * 10 + s[i] - '0';
            } else {
                num2 = num2 * 10 + s[i] - '0';
            }
        }
        // cout << num1 << endl << num2 << endl;
        long long temp = num1 * num2;
        if(temp > 0 && stoi(s) % int(temp) == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
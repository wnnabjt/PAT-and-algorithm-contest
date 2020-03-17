#include <iostream>
#include <string>
#include <stack>
using namespace std;

char s[10][10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int main() {
    string s1;
    cin >> s1;
    int sum = 0;
    for(int i = 0; i < s1.size(); i ++) {
        sum += s1[i] - '0';
    }
    stack <string> _stack;
    while(sum) {
        _stack.push(s[sum % 10]);
        sum /= 10;
    }
    if(!_stack.empty()) {
        cout << _stack.top();
        _stack.pop();
    } else cout << "zero";
    while(!_stack.empty()) {
        cout << ' ' << _stack.top();
        _stack.pop();
    }
    cout << endl;
    return 0;
}

/*
    �ݹ�ѭ�������ԣ������õݹ顣��Ҫ�Ǻܾ�ûд�ݹ�����ˣ���΢��ϰһ�¡�
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

void print(int a, int d) {
    if(a > 0) print(a / d, d);
    if(a > 0) printf("%d", a % d);
}

int main() {
    int a, b, d;
    while(cin >> a >> b >> d) {
        a = a + b;
        print(a, d);
        printf("\n");
    }
    return 0;
}

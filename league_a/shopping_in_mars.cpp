#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;

int min(int a, int b) {
    return a < b ? a : b;
}

const int inf = 0x3f3f3f3f;

vector <int> vec, sum;

int main() {
    int n, k, diamonds, temp;
    cin >> n >> k;
    sum.push_back(0);
    vec.push_back(0);
    for(int i = 1; i <= n; i ++) {
        cin >> diamonds;
        vec.push_back(diamonds);
        temp = sum[i - 1] + diamonds;
        sum.push_back(temp);
    }
    int low = 0, min_cost = inf;
    for(int i = 1; i <= n; i ++) {
        if(sum[i] - sum[low] >= k) {
            min_cost = min(min_cost, sum[i] - sum[low]);
            if(sum[i] - sum[low] == k) {
                cout << low + 1 << '-' << i << endl;
                low ++;
            } else {
                i --;
                low ++;
            }
        }
    }
    low = 0;
    if(min_cost != k) {
        for(int i = 1; i <= n; i ++) {
            if(sum[i] - sum[low] == min_cost) {
                cout << low + 1 << '-' << i << endl;
                low ++;
            } else if(sum[i] - sum[low] > min_cost) {
                low ++;
                i --;
            }
        }
    }
    return 0;
}
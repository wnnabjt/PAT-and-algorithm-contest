#include <iostream>
using namespace std;

int main() {
    int n, floor, now = 0;
    cin >> n;
    int ans = 0;
    while(n --) {
        cin >> floor;
        if(floor > now) {
            ans += 6 * (floor - now);
            now = floor;
        } else {
            ans += 4 * (now - floor);
            now = floor;
        }
        ans += 5;
    }
    cout << ans << endl;
    return 0;
}

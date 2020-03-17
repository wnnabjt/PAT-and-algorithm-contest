#include <cstdio>
using namespace std;

const int CLK_TCK = 100;

int main() {
    int c1, c2;
    scanf("%d %d", &c1, &c2);
    int time = (c2 - c1) / CLK_TCK;
    printf("%02d:%02d:%02d", time / 3600, (time % 3600) / 60, (time % 3600) % 60);
    return 0;
}

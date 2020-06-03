#include <cstdio>
using namespace std;

struct M {
    int galleon, sickle, knut;
} a, b, sum;

int main() {
    scanf("%d.%d.%d", &a.galleon, &a.sickle, &a.knut);
    scanf("%d.%d.%d", &b.galleon, &b.sickle, &b.knut);
    int temp = 0;
    sum.knut = (a.knut + b.knut) % 29;
    temp = (a.knut + b.knut) / 29;
    sum.sickle = (a.sickle + b.sickle + temp) % 17;
    temp = (a.sickle + b.sickle + temp) / 17;
    sum.galleon = a.galleon + b.galleon + temp;
    printf("%d.%d.%d\n", sum.galleon, sum.sickle, sum.knut);
    return 0;
}
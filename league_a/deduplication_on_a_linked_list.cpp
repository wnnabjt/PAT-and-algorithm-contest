#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

const int maxn = 1000000 + 5, maxm = 10000 + 5;

struct Link {
    int data, next;
} lists[maxn];

int vis[maxm];

vector <int> vec, link, dele;

int main() {
    int head, n;
    int from, data, to;
    scanf("%d %d", &head, &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d %d %d", &from, &data, &to);
        lists[from] = Link{data, to};
    }
    while(~head) {
        vec.push_back(head);
        head = lists[head].next;
    }
    for(int i = 0; i < vec.size(); i ++) {
        if(!vis[int(abs(lists[vec[i]].data))]) {
            vis[int(abs(lists[vec[i]].data))] = true;
            link.push_back(vec[i]);
        } else {
            dele.push_back(vec[i]);
        }
    }
    for(int i = 0; i < link.size() - 1; i ++) {
        printf("%05d %d %05d\n", link[i], lists[link[i]].data, link[i + 1]);
    }
    printf("%05d %d -1\n", link[link.size() - 1], lists[link[link.size() - 1]].data);
    if(dele.size()) {
        for(int i = 0; i < dele.size() - 1; i ++) {
            printf("%05d %d %05d\n", dele[i], lists[dele[i]].data, dele[i + 1]);
        }
        printf("%05d %d -1\n", dele[dele.size() - 1], lists[dele[dele.size() - 1]].data);
    }
    return 0;
}
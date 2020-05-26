#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e6 + 5, inf = 27;

vector <int> vec[maxn];

int Hash(string name) {
    return (name[0] - 'A' + 1) * inf * inf * 10 + (name[1] - 'A' + 1) * inf * 10 + (name[2] - 'A' + 1) * 10 + (name[3] - '0' + 1);
}

int main() {
    int n, k;
    cin >> n >> k;
    int id, num;
    string name;
    for(int i = 0; i < k; i ++) {
        cin >> id >> num;
        for(int i = 0; i < num; i ++) {
            cin >> name;
            vec[Hash(name)].push_back(id);
        }
    }
    for(int i = 0; i < n; i ++) {
        cin >> name;
        sort(vec[Hash(name)].begin(), vec[Hash(name)].end());
        cout << name << ' ' << vec[Hash(name)].size();
        for(int i = 0; i < vec[Hash(name)].size(); i ++) {
            cout << ' ' << vec[Hash(name)][i];
        }
        cout << endl;
    }
    return 0;
}
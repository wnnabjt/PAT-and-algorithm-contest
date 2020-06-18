#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Stu {
    string name, id;
    int grade;
};
vector <Stu> stu;

bool cmp(const Stu a, const Stu b) {
    return a.grade > b.grade;
}

int main() {
    string name, id;
    int n, grade;
    cin >> n;
    while(n --) {
        cin >> name >> id >> grade;
        stu.push_back(Stu{name, id, grade});
    }
    sort(stu.begin(), stu.end(), cmp);
    int l, r;
    cin >> l >> r;
    bool flag = false;
    for(int i = 0; i < stu.size(); i ++) {
        if(stu[i].grade < l || stu[i].grade > r) continue;
        flag = true;
        cout << stu[i].name << ' ' << stu[i].id << endl;
    }
    if(!flag) cout << "NONE" << endl;
    return 0;
}
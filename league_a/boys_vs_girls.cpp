#include <iostream>
#include <string>
using namespace std;

const int maxn = 1000 + 5, inf = 100 + 5;

struct Stu {
    string name, id;
    char gender;
    int grade;
} stu[maxn];

int main() {
    int n;
    cin >> n;
    int min = -1, max = -1;
    int max_grade = 0, min_grade = inf;
    for(int i = 0; i < n; i ++) {
        cin >> stu[i].name >> stu[i].gender >> stu[i].id >> stu[i].grade;
        if(stu[i].gender == 'F') {
            if(stu[i].grade > max_grade) {
                max_grade = stu[i].grade;
                max = i;
            }
        } else {
            if(stu[i].grade < min_grade) {
                min_grade = stu[i].grade;
                min = i;
            }
        }
    }
    if(~max) {
        cout << stu[max].name << ' ' << stu[max].id << endl;
    } else cout << "Absent" << endl;
    if(~min) {
        cout << stu[min].name << ' ' << stu[min].id << endl;
    } else cout << "Absent" << endl;
    if(!~max || !~min) {
        cout << "NA" << endl;
    } else cout << stu[max].grade - stu[min].grade << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 100 + 5, inf = 0x3f3f3f3f;

struct Stu {
    string id;
    int score, final_rank, location_number, local_rank;
};

vector <Stu> ans;
vector <Stu> stu[maxn];

bool cmp1(Stu a, Stu b) {
    return a.score > b.score;
}

bool cmp2(Stu a, Stu b) {
    if(a.score == b.score) return a.id < b.id;
    return a.score > b.score;
}

int cnt;

int main() {
    int n, k, score;
    string id;
    Stu temp;
    while(cin >> n) {
        for(int i = 1; i <= n; i ++) {
            cin >> k;
            for(int j = 1; j <= k; j ++) {
                cin >> id >> score;
                stu[i].push_back(Stu{id, score, inf, i, inf});
            }
        }
        for(int i = 1; i <= n; i ++) {
            sort(stu[i].begin(), stu[i].end(), cmp1);
            temp = stu[i][0];
            cnt = 1;
            stu[i][0].local_rank = 1;
            ans.push_back(Stu{temp.id, temp.score, temp.final_rank, temp.location_number, cnt});
            for(int j = 1; j < stu[i].size(); j ++) {
                cnt ++;
                temp = stu[i][j];
                if(temp.score == stu[i][j - 1].score) ans.push_back(Stu{temp.id, temp.score, temp.final_rank, temp.location_number, stu[i][j].local_rank = stu[i][j - 1].local_rank});
                else ans.push_back(Stu{temp.id, temp.score, temp.final_rank, temp.location_number, stu[i][j].local_rank = cnt}); // stu[i][j].local_rank = cnt 这里，如果这里不修改值，那么遇到连续的排名相同会导致后面的同学无排名，，，，
            }
        }
        sort(ans.begin(), ans.end(), cmp2);
        ans[0].final_rank = 1;
        cnt = 1;
        for(int i = 1; i < ans.size(); i ++) {
            cnt ++;
            if(ans[i].score == ans[i - 1].score) ans[i].final_rank = ans[i - 1].final_rank;
            else ans[i].final_rank = cnt;
        }
        cout << ans.size() << endl;
        for(int i = 0; i < ans.size(); i ++) {
            temp = ans[i];
            cout << temp.id << ' ' << temp.final_rank << ' ' << temp.location_number << ' ' << temp.local_rank << endl;
        }
    }
    return 0;
}

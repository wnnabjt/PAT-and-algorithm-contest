#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack <char> s;
	string a, b;
	int cnt = 0;
	cin >> a >> b;
	int A = stoi(a), B = stoi(b), C = A + B;
	string ans = to_string(C);
	for(int i = ans.size() - 1; i >= 0; i --) {
		if(cnt == 3 && ans[i] != '-') {
			s.push(',');
			cnt = 0;
		}
		s.push(ans[i]);
		cnt ++;
	}
	char c;
	while(!s.empty()) {
		c = s.top(); s.pop();
		cout << c;
	}
	cout << endl;
	return 0;
}

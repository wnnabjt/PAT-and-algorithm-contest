#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Patient{
    string ID;
    string name;
    int age;
    string sex;
    string blood;
    queue<double> q;  //血压测量历史
    string doctorname;
    string treatment_programs;
};

map<string, Patient> sys;

void sol(string ID, int op);
void Reload();
void Record(string ID);
void Newpatient();
void Search(string ID);
void Delete(string ID);
void Output();

int main()
{
    Reload();
    int op;
    string ID;
    while(1) {
        cout << "Please enter the operation code you want to perform: " << endl;
        cout << "1. Search patient information." << endl;
        cout << "2. Record patient measurement." << endl;
        cout << "3. Delete patient information." << endl;
        cout << "4. Create patient information." << endl;
        cout << "5. Save and exit." << endl;
        cin >> op;
        if(op == 4) {
            Newpatient();
        }
        else if(op == 5) {
            Output();
            break;
        }
        else {
            cout << "Please input the patient's ID: ";
            cin >> ID;
            sol(ID, op);
        }
    }
    return 0;
}

void sol(string ID, int op) {
    map<string, Patient>:: iterator it = sys.find(ID);
    if(it == sys.end()) {
        cout << "This person does not exist." << endl;
        system("pause");
    }
    else {
        switch (op)
        {
        case 1:
            Search(ID);
            break;
        case 2:
            Record(ID);
            break;
        case 3:
            Delete(ID);
            break;
        default:
            break;
        }
    }
}

void Reload() {
    streambuf *backup;
    ifstream fin;
    fin.open("Info.txt");
    backup = cin.rdbuf();
    cin.rdbuf(fin.rdbuf());
    int num;
    string ID;
    int t;
    double tmp;
    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> ID;
        sys[ID].ID = ID;
        cin >> sys[ID].name >> sys[ID].age >> sys[ID].sex >> sys[ID].blood;
        cin >> t;
        while(t--) {
            cin >> tmp;
            sys[ID].q.push(tmp);
        }
        cin >> sys[ID].doctorname >> sys[ID].treatment_programs;
    }
    cout << "Reload completed." << endl;
    cin.rdbuf(backup);
}

void Newpatient() {
    string ID;
    cout << "Please input ID: ";
    cin >> ID;
    cout << "Please input name: ";
    cin >> sys[ID].name;
    cout << "Please input age: ";
    cin >> sys[ID].age;
    cout << "Please input sex: ";
    cin >> sys[ID].sex;
    cout << "Please input blood type: ";
    cin >> sys[ID].blood;
    cout << "Create patient information completed." << endl;
    Record(ID);
}

void Record(string ID) {
    double bp;
    cout << "Please enter the blood pressure: ";
    cin >> bp;
    sys[ID].q.push(bp);
    int t = sys[ID].q.size();
    if(t > 10) {
        sys[ID].q.pop();
    }
    cout << "Record completed." << endl;
    double avg = 0;
    for(int i = 0; i < t; i++) {
        double tmp = sys[ID].q.front();
        avg += tmp;
        sys[ID].q.pop();
        sys[ID].q.push(tmp);
    }
    avg /= t;
    if(avg >= 140) {
        cout << "Last " << t << " measurements average is " << avg << ". This patient may have high blood pressure and need timely treatment." << endl;
    }
    else if(avg >= 120 && avg < 140) {
        cout << "Last " << t << " measurements average is " << avg << ". This patient need to adjust his/her lifestyle in time." << endl;
    }
    else {
        cout << "This person is healthy." << endl;
    }

    if(sys[ID].doctorname.size() != 0) {
        cout << "Last time Doctor " << sys[ID].doctorname << " provided treatment programs: " << sys[ID].treatment_programs << endl;
    }
    cout << "Please enter your name: ";
    cin >> sys[ID].doctorname;
    cout << "Please enter your treatment programs: ";
    cin >> sys[ID].treatment_programs;
    system("pause");
}

void Search(string ID) {
    cout << "ID: " << sys[ID].ID << endl;
    cout << "Name: " << sys[ID].name << endl;
    cout << "Age: " << sys[ID].age << endl;
    cout << "Sex: " << sys[ID].sex << endl;
    cout << "BloodType: " << sys[ID].blood << endl;
    int t = sys[ID].q.size();
    cout << "Last " << t << " measurements: ";
    while(t--) {
        double tmp = sys[ID].q.front();
        cout << tmp << ' ';
        sys[ID].q.pop();
        sys[ID].q.push(tmp);
    }
    cout << endl << "Last time Doctor " << sys[ID].doctorname << " provided treatment programs: " << sys[ID].treatment_programs << endl;
    system("pause");
}

void Delete(string ID) {
    sys.erase(ID);
    cout << "Delete completed." << endl;
    system("pause");
}

void Output() {
    freopen("Info.txt", "w", stdout);
    cout << sys.size() << endl;
    map<string, Patient>:: iterator it;
    for(it = sys.begin(); it != sys.end(); it++) {
        cout << it->first << "  ";
        cout << it->second.name << "  ";
        cout << it->second.age << "  ";
        cout << it->second.sex << "  ";
        cout << it->second.blood << "  ";
        int t = it->second.q.size();
        cout << t << "  ";
        while(t--) {
            cout << it->second.q.front() << ' ';
            it->second.q.pop();
        }
        cout << it->second.doctorname << ' ' << it->second.treatment_programs << endl;
    }
}
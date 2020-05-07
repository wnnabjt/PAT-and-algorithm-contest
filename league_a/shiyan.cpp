# include <iostream>
# include <string>
using namespace std;
class Building
{
    public:
        Building(string s,string n)
        {
            address=s;
            id = n;
        }
    protected:
        string address;
        string id;
};

class House:virtual public Building
{
    public:
        House(string s, string n, string area, string id):Building(s, n),area(area), id_of_room(id){}

    protected:
        string area;
        string id_of_room;
};
class Office:virtual public Building
{
    public:
        Office(string s, string n, string name, string phone_num):Building(s, n),name(name), phone_num(phone_num){}
    protected:
        string name;
        string phone_num;
};
class Home:public Office,public House
{
public:
	Home(string address, string n, string name, string phone_num, string id, string area):Building(address,n),
        Office(address, n, name, phone_num),House(address, n, area, id){}
	void show()
	{
		cout<<"address is :"<<address<<endl;
		cout<<"louhao is ��"<<id<<endl;
		cout<<"office_name is ��"<<name<<endl;
		cout<<"telephone num is :"<<phone_num<<endl;
		cout<<"id of room is :"<<id_of_room<<endl;
		cout<<"area is :"<<area<<endl;	
	}

};
int main()
{
	Home h("shanxi", "1b", "shankeda", "1234", "666", "123.45");
    h.show();
	return 0;
}
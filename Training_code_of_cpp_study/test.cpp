#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;
string name[10] = {"gnil", "iy", "re", "nas", "is", "uw", "uil", "iq", "ab", "uij"};
int main()
{
    string n, result;
    cin>>n;
    if(n[0]=='0'&&n.length()==1) cout<<"ling";
    else{
        bool isPositive = true;
        if(n[0]=='-'){
            isPositive = false;
            n.erase(n.begin());//删负号
        }
        reverse(n.begin(), n.end());//低位在前
        int zeroLen = 0;//记录尾部0的个数
        for(int i=0;i<n.length();i++){
            if(n[i]!='0') break;
            zeroLen ++;
        }
        bool flag = false;
        for(int i=0;i<n.length();i++){
            if(i%4==0){
                if(i/4==1){
                    result += "naW ";
                }
                else if(i/4==2){
                    result += "iY ";
                }
            }
            else if(i%4==1&&n[i]!='0'){
                result += "ihS ";
            }
            else if(i%4==2&&n[i]!='0'){
                result += "iaB ";
            }
            else if(i%4==3&&n[i]!='0'){
                result += "naiQ ";
            }
            if(n[i]!='0'){
                flag = false;
                result += name[n[i]-'0'];
                result += ' ';
            }
            else if(n[i]=='0'&&i>zeroLen&&flag==false){
                flag = true;//防止出现2个及以上的0输出多个"ling"
                result += name[n[i]-'0'];
                result += ' ';
            }
        }
        reverse(result.begin(), result.end());
        if(isPositive==false) result.insert(0, "Fu");
        if(result[0]==' ') result.erase(result.begin());//删去头部的空格
        if(result[result.length()-1]==' ') result.erase(result.begin()+result.length()-1);//删去尾部的空格
        cout<<result;
    }
    return 0;
}

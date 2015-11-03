#include <iostream>
#include<string>
using namespace std;

string turnSixteen(int a){
    string s="";
    while(a>0){
        int t=a%16;
        if(t<=9){
            char as=t+48;
            s.insert(s.begin(),as);
        }else{
            if(t==10)
                s.insert(s.begin(),'A');
            if(t==11)
                s.insert(s.begin(),'B');
            if(t==12)
                s.insert(s.begin(),'C');
            if(t==13)
                s.insert(s.begin(),'D');
            if(t==14)
                s.insert(s.begin(),'E');
            if(t==15)
                s.insert(s.begin(),'F');
        }
        a=a/16;
    }
    return s;
}
int main()
{
    string s =turnSixteen(65155028);
    cout<<s<<endl;
    return 0;
}

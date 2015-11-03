#include <iostream>
#include <cstdint>
#include<string>
using namespace std;

int main()
{
    uint32_t t1=8;
    string s="10000000000000000000000000000000";
    cout<<s.size()<<endl;
//    s.push_back(1+48);
//    cout<<s<<endl;
    while(t1>0){
        if(t1%2==0){
            s.push_back('0');
        }
        else{
            s.push_back('1');
        }
        t1=t1/2;
    }
    cout<<s<<endl;
    return 0;
}

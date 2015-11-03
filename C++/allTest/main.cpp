#include <iostream>
#include<map>
#include<set>
using namespace std;

int main()
{
    set<int> set1;
    set<pair<int,int>> set2;
    set1.insert(1);
    set1.insert(2);
    set2.insert(make_pair(1,2));
    set2.insert(make_pair(2,2));
    cout<<set1.size()<<endl;
    cout<<set2.size()<<endl;
    return 0;
}

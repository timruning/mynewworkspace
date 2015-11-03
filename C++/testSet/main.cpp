#include <iostream>
#include<set>
#include<string>
using namespace std;

int main()
{
    set<int> se={1,2,3,4};
    for(auto s:se){
        cout<<s<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}

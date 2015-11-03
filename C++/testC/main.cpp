#include <iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cstdlib>
#include<windows.h>
#include<time.h>
using namespace std;
int myrandom(int i){return rand()%i;}
typedef int(*g)(int);
void random(int *a,int *b,g gen){
    int n=b-a;
    for(int i=n-1;i>0;--i){
        swap(a[i],a[gen(i+1)]);
    }
}
/*template <class RandomAccessIterator, class RandomNumberGenerator>
  void random(RandomAccessIterator first, RandomAccessIterator last,
                       RandomNumberGenerator& gen)
{
  int i, n;
  n = (last-first);
  for (i=n-1; i>0; --i) {
    swap (first[i],first[gen(i+1)]);
  }
}*/
int main()
{
    srand(time(nullptr));
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    random(a,a+10,myrandom);
    for(int i=0;i<10;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

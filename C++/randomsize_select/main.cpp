#include <iostream>
#include<algorithm>
using namespace std;
//寻找第i小的数

int random_partition(int a[],int p,int r){
//    cout<<"r = "<<r<<endl;
    int i=rand()%(r-p+1)+p;
//    cout<<"i ="<<i<<endl;
    swap(a[i],a[r]);
    int x=a[r];
    int count=p-1;
    for(int j=p;j<r;j++){   //从p开始划分到r结束
        if(a[j]<x){
            count++;
            swap(a[count],a[j]);
        }
    }
    swap(a[count+1],a[r]);
    return count+1;
}
int random_select(int a[],int p,int r,int i){
    if(p==r){
        return a[p];
    }
    int q=random_partition(a,p,r);
    int k=q-p+1;
    if(k==i){
        return a[q];
    }
    else if(i<k){
        return random_select(a,p,q-1,i);
    }else{
        return random_select(a,q+1,r,i-k);
    }
}
int main()
{
    int a[10]={2,3,5,21,5,2,3,53,6,34};
    int x=random_select(a,0,9,8);
    cout<<x<<endl;
    return 0;
}

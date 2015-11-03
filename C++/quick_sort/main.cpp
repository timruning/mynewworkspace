#include <iostream>
#include<algorithm>
using namespace std;
int partition_s(int a[],int p,int r){
    int x=a[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(x>a[j]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
int random_partition(int a[],int p,int r){
    int i=rand()%(r-p+1)+p;
    swap(a[i],a[r]);
    return partition_s(a,p,r);
}
void quick_sort(int a[],int p,int r){
    if(p<r){
        int q=partition_s(a,p,r);
    quick_sort(a,p,q-1);
    quick_sort(a,q+1,r);
    }
}
void quick_sort(int a[],int n){
    quick_sort(a,0,n-1);
}
void random_quick_sort(int a[],int p,int r){
    if(p<r){
        int q=random_partition(a,p,r);
        random_quick_sort(a,p,q-1);
        random_quick_sort(a,q+1,r);
    }
}
int main()
{
    int a[10]={1,3,52,10,4,23,7,5,6,3};
/*    quick_sort(a,5,9);*/
//    random_quick_sort(a,0,9);
    quick_sort(a,10);
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

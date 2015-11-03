#include <iostream>

using namespace std;
void sort(int a[],int p,int r){
    for(int i=p+1;i<=r;i++){
        for(int j=i-1;j>=p;j--){
            if(a[j+1]<a[j]){
                swap(a[j+1],a[j]);
            }
        }
    }
}
int partition(int a[],int p,int r,int st){
    int i=p-1;
    int count;
    for(int j=p;j<=r;j++){
        if(a[j]==st){
            count=j;
        }else if(a[j]<st){
            i++;
            swap(a[j],a[i]);
        }
    }
    swap(a[i+1],a[count]);
    return i+1;
}
int on_select(int a[],int p,int r,int icount){
    if(p==r)
        return a[p];
    int k=(r-p+1)/5;
    if((r-p+1)%5)
        k++;
    int b[k];
    int pp=0;
    for(int i=p;i<=r;i=i+5){
        if(i+4<=r){
            sort(a,i,i+4);
            b[pp]=a[i+2];
            pp++;
        }else{
            sort(a,i,r);
            b[pp]=a[(i+r)/2];
            pp++;
        }
    }
    int st = on_select(b,0,k-1,k/2);
    int q=partition(a,p,r,st);
    int kcount=q-p+1;
    if(kcount==icount)
        return a[q];
    else if(kcount<icount){
        return on_select(a,q+1,r,icount-kcount);
    }else{
        return on_select(a,p,q-1,icount);
    }
}
int main()
{
    int a[11]={2,3,2,5,1,32,23,9,54,4,13};
 //   sort(a,0,9);
    for(int i=0;i<11;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    int s=on_select(a,0,10,8);
    cout<<s<<endl;
    sort(a,0,10);
    for(int i=0;i<11;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}

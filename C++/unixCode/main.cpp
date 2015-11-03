#include <iostream>

using namespace std;
int minimum(int a[],int n){
    int min=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<min)
            min=a[i];
    }
    return min;
}
int* maxminFind(int a[],int n){
    int maxmin[2];
    if(a[0]<a[1]){
        maxmin[0]=a[0];
        maxmin[1]=a[1];
    }else{
        maxmin[0]=a[1];
        maxmin[1]=a[0];
    }
    for(int i=3;i<n;i=i+2){
        int min=a[i];
        int max;
        if(i+1<n){
            if(a[i]<a[i+1]){
                min=a[i];
                max=a[i+1];
            }else{
                min=a[i+1];
                max=a[i];
            }
            if(min<maxmin[0]){
                maxmin[0]=min;
            }
            if(max>maxmin[1]){
                maxmin[1]=max;
            }
        }else{
            if(a[i]<maxmin[0]){
                maxmin[0]=a[i];
            }
            if(a[i]>maxmin[0]){
                maxmin[1]=a[i];
            }
        }
    }
    return maxmin;
}
int partitions(int a[],int p,int r){
    int x=a[r];
    int i=p-1;
    for(int j=p;j<r;j++){
        if(a[j]<=x){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}
void quicksort(int a[],int p,int r){
    if(p<r){
        int q=partitions(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }
}
int random_partition(int a[],int p,int r){
 //   int i=rand(p,r);

}
int randomized_select(int a[],int p,int r,int i){
    if(p==r){
        return a[p];
    }
    int q=random_partition(a,p,r);
    int k=q-p+1;
    if(i==k)
        return a[p];
    else if(i<k){
        return randomized_select(a,p,q-1,r);
    }
}
int main()
{
    int a[10]={0,3,2,6,1,3,5,6,10z,8};
    quicksort(a,1,8);
    for(int i=0;i<10;i++){
        cout<<a[i]<<" "<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

void merge(int *arr,int l,int m,int r){
    int size1=m-l+1,size2=r-m;
    vector<int> vec1(size1),vec2(size2);
    for(int i=0;i<size1;i++){
        vec1[i]=arr[l+i];
    }
    for(int i=0;i<size2;i++){
        vec2[i]=arr[m+1+i];
    }
    int first=0,second=0,i=l;
    while (first<size1 && second<size2){
        if(vec1[first]<vec2[second]){
            arr[i]=vec1[first++];
        }
        else
        {
            arr[i]=vec2[second++];
        }
        i++;
    }
    while (first<size1)
    {
        arr[i++]=vec1[first++];
    }
    while (second<size2)
    {
        arr[i++]=vec2[second++];
    }
    
   
    
}
void mergesort(int *arr,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    int arr[]={8,4,2,6,9,1,3};
    mergesort(arr,0,7);
    for(auto c:arr){
        cout<<c<<" ";
    }
    return 0;
}
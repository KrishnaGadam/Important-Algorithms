#include<bits/stdc++.h>
using namespace std;

int partition(int *arr,int l,int r){
    int pivot=arr[r];
    int k=l-1;
    for(int i=l;i<r;i++){
        if(arr[i]<pivot){
            k++;
            swap(arr[k],arr[i]);
        }
    }
    swap(arr[k+1],arr[r]);
    return k+1;
}
void quicksort(int* arr,int l,int r){
    if(l<r){
        int pivot=partition(arr,l,r);
        quicksort(arr,l,pivot-1);
        quicksort(arr,pivot+1,r);
    }
    
}
int main(){
    int arr[]={5,7,8,2,3,4,1};
    quicksort(arr,0,6);
    for(auto c:arr){
        cout<<c<<" ";
    }
    return 0;
}
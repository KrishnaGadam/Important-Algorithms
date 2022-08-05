#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={4,6,7,2,1,5,3};
    for(int i=0;i<6;i++){
        for(int j=1;j<7-i;j++){
            if(arr[j-1]>arr[j])swap(arr[j],arr[j-1]);
        }
    }
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
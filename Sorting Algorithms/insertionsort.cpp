#include<bits/stdc++.h>
using namespace std;


int main(){
    int arr[]={4,5,2,7,1,3};
    int val,j;
    for(int i=1;i<6;i++){
        val=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>val){
            arr[j+1]=arr[j];
            j-=1;
        }
        arr[j+1]=val;
        
    }
    for(auto c:arr){
            cout<<c<<" ";
        }
    return 0;
}
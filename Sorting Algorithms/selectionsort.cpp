#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[6]={4,6,3,2,9,6};
    for(int i=0;i<5;i++){
        int mn=i;
        for(int j=i+1;j<6;j++){
            if(arr[j]<arr[mn])mn=j;
        }
        swap(arr[i],arr[mn]);
    }
    for(auto c:arr){
        cout<<c<<" ";
    }
    return 0;
}
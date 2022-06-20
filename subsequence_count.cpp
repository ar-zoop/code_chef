#include <bits/stdc++.h>
using namespace std;

int sub(int idx, int sum, int arr[], int n, int target){
    if(idx==n){
        if (sum==target){
            return 1;
        }
        return 0;
    }
    //take
    // v.push_back(arr[idx]);
    int l=sub(idx+1, sum+arr[idx],arr, n, target);
    // v.pop_back();

    //not take
    int r= sub(idx+1, sum,arr,  n, target);
    return l+r;
}

int main(){
    int t, sum;
    cout<<"enter number of elements in array: ";
    cin>>t;
    int arr[t];
    cout<<"enter elements: ";
    for (int i=0;i<t;i++){
        cin>>arr[i];
    }
    cout<<"Enter sum: ";
    cin>>sum;
    int count=sub(0,0,arr,t,sum);
    cout<<count;
}
#include <bits/stdc++.h>
using namespace std;

bool sub(int ele,vector<int> arr, int n){
    int low=0, high= n-1;
    if(arr[0]<arr[n-1]){
        int mid=(low+high)/2;
        while(low<=high){
            if(arr[mid]==ele) return true;
            else if(arr[mid]>ele){
                high=mid-1;
            }
            else low=mid+1;
        }
    }
    else{
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]==ele) return true;
            if(arr[0]<arr[mid]){
                if(arr[low]<=ele && ele<arr[mid]){
                    high=mid-1;
                }
                else
                    low=mid+1;
            }
            else {
                if(arr[mid]<ele && ele<=arr[high]) low=mid+1;
                else high=mid-1;
            }
        }
    }
    return false;
}
int findPairSum(vector<int> arr, int target){    
    int n=sizeof(arr)/sizeof(int);
    int flag=0;
    for(int i=0;i<n;i++){
        int ele=target-arr[i];
//         cout<<arr[i]<<' ';
        if(ele<0) continue;
        
        else if(sub(ele, arr, n)){
//             cout<<"YES";
            flag=1;
            break;
        }
        else continue;
    }
    if(flag==0) return 0;  return 1;
}
#include <bits/stdc++.h>
using  namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, c;
        cin>>n>>c;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr, arr+n);
        int maxdiff=arr[n-1];
        int diff[maxdiff]={0};
        for(int i=0; i<maxdiff; i++){
            diff[i]=i+1;
        }


        int low=1, high=maxdiff, mid, count=0, maxi=1;
        while(low<=high){
            mid=(low+high)/2;
            // cout<< diff[mid]<<" ";
            int prev=0;
            int flag=0;
            count=1;
            for(int cur=1; cur<n; cur++){
                if(arr[cur]-arr[prev] >= diff[mid]){
                    prev=cur;
                    count++;
                }
                if(count==c) {
                    flag=1;
                    maxi=diff[mid];
                    break;
                }
            }
            if(flag==1){
                low=mid+1;
                // diff[low];
            }
            else{
                high=mid-1;
            }

        }
        cout<<maxi;
    }
    return 0;
} 
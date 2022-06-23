#include <bits/stdc++.h>
using namespace std;

int sub(int idx, int sum, int target, int k[], int n){
    int left=INT_MAX, right=INT_MAX, mid=INT_MAX;
    //base cases
    if(idx==n-1)return 0;
    if(sum==target) {return 0;cout<<"hi"}
    if((sum+k[idx])<=target){
        //pick the same
        left=sub(idx, sum+k[idx], target, k, n)+1;    
        //pick and go to next
        mid=sub(idx+1, sum+k[idx], target, k, n)+1;        
        //not pick and go to next
        right=sub(idx+1, sum+0, target, k, n)+0;
    }
    
    //return best
    int minimum=min(left,right);
    return min(minimum, mid);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n;
        int h[n],k[n];
        for(int i=0;i<n;i++){ 
            cin>>a;
            h[i]=2*a;}
        for(int i=0;i<n;i++) cin>>k[i];
        sort(k,k+n);
        for (int i=0;i<n;i++){
            a=sub(0,0,h[i],k, n);
            cout<<a;
        }
       
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int memo[1000][1000];

int sub(int idx, int target, int k[], int n){
    int take=INT_MAX, not_take=INT_MAX;
    //base cases
    if(idx==n){
        if(target==0){
            return 0;
        }
        return 10000000;
    }
    if(memo[idx][target]!=-1)return memo[idx][target];
    //take,not_take
    if((k[idx])<=target){
     take=sub(idx,target-k[idx],k,n)+1;
    }
    not_take=sub(idx+1,target,k,n)+0;
    
    //return best
    return memo[idx][target]= min(take, not_take);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        memset(memo,-1,sizeof(memo));
        int n,a;
        cin>>n;
        int h[n],k[n];
        for(int i=0;i<n;i++){ 
            cin>>a;
            h[i]=2*a;
        }
        for(int i=0;i<n;i++) cin>>k[i];
        // sort(k,k+n);
        a=0;
        for (int i=0;i<n;i++){
            a+=sub(0,h[i],k, n);
            
        }
        cout<<a<<endl;
    }
    return 0;
}
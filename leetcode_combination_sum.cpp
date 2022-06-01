/*
#include <bits/stdc++.h>
using namespace std;


int sub(int idx, int s, int sum, int c[],int n, vector<int>v){
    if(idx==n){
        if(s==sum){
            for(auto x: v) cout<<x<<" ";
            cout<<endl;
        }
        return;
    }
    //take element
    v.push_back(c[idx]);
    s+=c[idx];
    sub(idx+1,s,sum, c,n,v);
    sub(idx,s,sum,c,n,v);
    //do not take element
    v.pop_back();
    s-=c[idx];
    sub(idx+1,s,sum, c,n,v);
    sub(idx,s,sum,c,n,v);
}

int main(){
    vector<int>v;
    int n=-1;
    int candidates[30],i=0;
    while(candidates[i]!='\n'){
        n++;
        cin>>candidates[i];
        i++;
    }
    int target;
    cin>>target;
    sub(0,0,target,candidates,n,v);
}
*/
class Solution {

public:
    void f(int idx, int target, vector<int> &v, vector<int>&arr, vector<vector<int>>&ans){
        if(idx == arr.size() || target == 0){
            if(target==0 ){
                ans.push_back(v);
                return;
            }
            return;
        }
        //pick
        if(arr[idx]<=target){
            v.push_back(arr[idx]);
            f(idx, target-arr[idx],v,arr,ans);   
            v.pop_back();
        }
        //not pick
        // if(target-arr[idx+1]>=0){
            f(idx+1, target,v,arr,ans);
        // }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        f(0,target,v,candidates,ans);
        return ans;
    }
};
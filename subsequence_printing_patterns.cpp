#include <bits/stdc++.h>
using namespace std;

int arr[3]={1,2,1};
int n=3;
//all subsequence printing
void sub(vector<int>&v ,int idx){
    if(idx>=n) {
        for (auto x: v) cout<<x<<" ";
        cout<<endl;
        return;
    }
    v.push_back(arr[idx]);
    sub(v, idx+1);
    v.pop_back();
    sub(v,idx+1);
}

//all subsequence printing with sum=3
void sub2(vector<int>&v ,int idx,int sum){
    if(idx>=n) {
        if(sum==3) {
            for(auto x: v) cout<<x<<" ";
             cout<<endl;
           
        }
       
        return;
    }
    v.push_back(arr[idx]);
    sum+=arr[idx];
    sub2(v, idx+1,sum);
    v.pop_back();
    sum-=arr[idx];
    sub2(v,idx+1,sum);
}

// only 1 subsequence printing with sum=3
bool isFound(vector<int>&v, int idx, int sum){
    if(idx==n){
        if(sum==3){
            for(auto x: v) cout<<x<<" ";
            cout<<endl;
            return true;

        }
        return false;
    }
    //take
    v.push_back(arr[idx]);
    sum+=arr[idx];
    if(isFound(v, idx+1,sum)){
        return true;
    }
    //dont take
    v.pop_back();
    sum-=arr[idx];
    if(isFound(v, idx+1,sum)){
        return true;
    }
    //by default
    return false;
}

//count the subsequences with sum=k
int count(int idx, int sum){
    if(idx==n){
        if(sum==3){
            return 1;
        }
        else return 0;
    }
    //take
  
    sum+=arr[idx];
    int l=count(idx+1,sum);

    //dont take
    
    sum-=arr[idx];
    int r=count(idx+1,sum);
    
    return l+r;
}

int main(){
    vector <int> v;
    // sub(v,0);
    // sub2(v,0,0);
    isFound(v,0,0);
    // int c=count(0,0);
    // cout<<c;
    return 0;
}
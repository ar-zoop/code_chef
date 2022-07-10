#include <bits/stdc++.h>
using namespace std;

/*
bool sub(int idx, int target,vector<int> &arr, int n){
    bool pick=false, not_pick=false;
    //base case
    if(target==0){
        return true;
    }
    if(idx==n-1){
        if(target==arr[idx]) return true;
        return false;
    }
    //memoization
    if(memo[idx][target]!=-1){
        return memo[idx][target];
    }

    //recurrence
    if(arr[idx]<=target){
        pick =sub(idx+1, target-arr[idx], arr,n);
        if(pick==true) {            
            return memo[idx][target]= true;
        }
    }
    not_pick=sub(idx+1, target, arr,n);
    if(not_pick==true) {
        return memo[idx][target]=true;
    }
   
    return  memo[idx][target]= false;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    memset(memo,-1,sizeof(memo));
    return sub(0,k,arr,n);
}

*/

//------------------TABULATION
vector<vector<int>>memo(4,vector<int>(8,-1));//memo[idx][target];
bool subsetSumToK(int n, int target, vector<int> &arr) {
   
    //BASE CASE conversion
    for (int i = 0;i<n;i++){
        memo[i][0]=true;
    }
    if(arr[n-1]<=target) memo[n-1][n-1]=true;
    
    for(int i=1;i<target;i++){
        memo[n-1][i]=false;        
    } 
   
    //form the nested loops. outer loop is idx, inner loop is target.
    //idx loop goes from starting to end of idx
    //we run the loop ULTA from what we did in recursion. idx - i went from 0 to n-1 so tabulation i go from n-1 to 0.
    for(int idx=n-2 ; idx>=1 ; idx--){//not n-1 co we've already done it
        for(int tar=1; tar<=target ; tar++){//not 0 coz we've already done 0
            //copy paste recurrence
            bool pick=false;
            if(arr[idx]<=tar){
                pick =memo[idx+1][tar-arr[idx]];
            }
            bool not_pick=memo[idx+1][tar];
            memo[idx][tar]= pick || not_pick;
        }
    }
}

int printVector(vector<int> arr){
    vector <int> :: iterator x;
    for(x= arr.begin(); x!= arr.end(); x++){
        cout<<*x<<" ";
    }
    cout<<endl;
}

int main(){
    int n=4;
    int k=7;
    vector<int> arr={1,2,3,4};
    bool a= subsetSumToK(n,k,arr);
    vector <vector<int>> :: iterator x;
    for(x= memo.begin(); x!=memo.end(); x++){
        printVector(*x);
    }
}
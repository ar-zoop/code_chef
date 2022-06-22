#include <bits/stdc++.h>
using namespace std;

int memo[100001];

int sub(int idx,  int n, vector<int> &heights, int k){
    int  minSteps= INT_MAX;
    //base cases
    if(idx==n-1) return 0;
    if(memo[idx]!=-1) return memo[idx];
    //take one-by-one
    for (int j=1;j<=k;j++){
        if(idx+j<n){
            int jump=sub(idx+j,n,heights, k) + abs(heights[idx]-heights[idx+j]);
            minSteps=min(minSteps,jump);
        }
    }
    
    memo[idx]=minSteps;
   return minSteps;
//     cout<<mini<<endl;
//     return mini;
    // return min;
}


int main()
{
    // Write your code here.
    int n,ele,maxJump;
    vector<int> heights;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements:\n";
    for (int i=0;i<n;i++){
        cin>>ele;
        heights.push_back(ele);
    }
    memset(memo,-1,sizeof(memo));
    cout<<"Enter the max number of steps the frog can jump: ";
    cin>>maxJump;
    int min= sub(0,n,heights, maxJump);
    
    
    cout<<min;

}
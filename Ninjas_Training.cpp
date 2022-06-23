#include <bits/stdc++.h>
using namespace std;

int memo[100000][100000];
int sub(int idx, int task, vector<vector<int>> &points, int n){
    int left,right;
    //base case
    
    if(idx>n-1){
        return 0;
    }
    if(memo[idx][task]!=-1)return memo[idx][task];
     if(task==0){
        //left    
        left= sub(idx+1,2, points, n )+points[idx][task];
        //right
        right= sub(idx+1,1, points, n )+points[idx][task];
        // return max(left, right);
    }

    if(task==1){
        //left    
        left= sub(idx+1,2, points, n  )+points[idx][task];
        //right
        right= sub(idx+1,0, points, n )+points[idx][task];
        // return max(left, right);
    }

     if(task==2){
        //left    
        left= sub(idx+1,0, points, n  )+points[idx][task];
        //right
        right= sub(idx+1,1, points, n )+points[idx][task];
        
    }
    return memo[idx][task]=max(left,right);
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    int max=INT_MIN;
    memset(memo, -1, sizeof(memo));
    for (int i=0;i<3;i++){
        int jump=sub(0,i, points, n);
        if(jump>max)max=jump;
    }
    return max;
}

int main(){
    int n=3;
    vector<vector<int>> points={{10,40,70},{20,50,80},{30,60,90}};
    int a=ninjaTraining(n, points);
    cout<<a;
}
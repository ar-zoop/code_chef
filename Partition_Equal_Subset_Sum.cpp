#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool sumChecker(int idx,int sum1, int sum2,std::vector<int>arr,int n , int &memo[][][]){
    //base case
    if(idx==n){
        if(sum1==sum2){
            return true;
        }
        return false;
    }
    if(memo[idx][sum1][sum2]!=-1) return memo[idx][sum1][sum2];

    //adding into sum1
    bool a= sumChecker(idx+1,sum1+arr[idx],sum2,arr, n,memo);
    if(a==true){
        return memo[idx][sum1][sum2]=1;
    }

    //adding  into sum2
    a=sumChecker(idx+1,sum1,sum2+arr[idx],arr, n,memo);
    if(a==true){
        return memo[idx][sum1][sum2]= 1;
    }

    //return
    return memo[idx][sum1][sum2]=0;
}

bool canPartition(std::vector<int> &arr,int n){
    int memo[100][10000][10000];
    memset(memo,-1,sizeof(memo));
    return sumChecker(0,0,0,arr,n,memo);
}

int  main(){    
    std:: vector<int>v={1,1,1,4};
    bool a=canPartition(v,4);
    std::cout<<a;
    return 0;
}
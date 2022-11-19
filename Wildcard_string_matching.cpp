#include <bits/stdc++.h>
class Solution{
    public:

   int memo[1000][1000];
    bool recur(int i, int j, string &wild, string &pattern){
        if(i<0 && j<0)  return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0) {
            
            for (int k=0; k<=i; k++){
                if(wild[k]!='*') return false;
            }
            return true;
        }
        if(memo[i][j]!=-1) return memo[i][j];
        if(wild[i]==pattern[j] || wild[i]=='?') return memo[i][j]= recur(i-1, j-1, wild, pattern);
        else if (wild[i]=='*'){
            if(recur(i-1, j,wild, pattern) || recur(i, j-1, wild, pattern)) return memo[i][j]= true;
            else return memo[i][j]= false;
        }
        else{
            return memo[i][j]= false;
        }
        
    }
    
    bool match(string wild, string pattern)
    {
        // code here
        for(int i=0; i<wild.length(); i++){
            for(int j=0; j<pattern.length(); j++){
                memo[i][j]=-1;
            }
        }
        return recur(wild.length()-1,pattern.length()-1,wild,pattern);
    }
};
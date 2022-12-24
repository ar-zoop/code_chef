//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
    }
 
    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if(i!=A.size()-1) cout << A[i]<< " ";
            else cout << A[i];
        }
        cout << endl;
    }
};


// } Driver Code Ends

// } Driver Code Ends
class Solution {
  public:
  
    bool isValid(string &s){
        stack<char> stk;
        int n=s.length();
        for(int i=0; i<n;i++){
            if(s[i]!='(' && s[i]!=')') continue;
            if(s[i]=='(') stk.push('(');
            else if(!stk.empty() && s[i]==')' && stk.top()=='('){
                stk.pop();
            }
            else{
                return false;
            }
        }
        if(!stk.empty())return false;
        return true;
    }
    
    void recur(int i, int count, string &temp, string &s, vector<string> &res){
        
        
        if(i==s.length()){
            if(count==0 && isValid(temp)){
                res.push_back(temp);
                    // return;
            }
            return;
        }
        // if(count==0) return;
        if(isalpha(s[i])){
            // cout<<s[i];
            temp=temp+s[i];
            // cout<<temp;
            return recur(i+1,count,temp,s,res);
        }
        string mod;
        mod=temp+s[i];
        recur(i+1,count-1,mod,s,res);
        recur(i+1,count,temp,s,res);
            
        
        return;
    }
    
    int getMinInvalids(string s, int n){
        stack<char> stk;
        int invalid=0;
        for(int i=0; i<n;i++){
            // cout<<s[i];
            if(s[i]=='(') stk.push('(');
            else if(!stk.empty() && s[i]==')' && stk.top()=='('){
                stk.pop();
            }
            else{
                // cout<<s[i]<<endl;
                invalid++;
            }
        }
        if(!stk.empty()) invalid+=stk.size();
        return invalid;
    }
    
    vector<string> removeInvalidParentheses(string s) {
        // code here
        
        vector<string> res;
        string temp="";
        int n=s.length();
        int invalid=getMinInvalids(s,n);
        // cout<<invalid<<endl;
        if(invalid==0){
            res.push_back(s);
            return res;
        }
        recur(0,n-invalid,temp,s,res);
        set<string> aux;
        int N=res.size();
        for(int i=0; i<N; i++){
            aux.insert(res[i]);
        }
        // N=aux.size();
        res.clear();
        set<string> :: iterator itr;
        // for(int i=0; i<N;i++){
        //     res.push_back(aux[i]);
        // }
        for(itr=aux.begin(); itr!=aux.end(); itr++){
            res.push_back(*itr)   ;
        }
        
        sort(res.begin(),res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        string s; 
        cin>>s;
        
        Solution obj;
        vector<string> res = obj.removeInvalidParentheses(s);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends
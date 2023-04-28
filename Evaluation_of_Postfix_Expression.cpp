//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string s)
    {
        // Your code here
        stack<int> st;
        int len=s.length();
        for(int i=0; i<len; i++){
            if(isdigit(s[i])){
                int num=s[i]-48;
                st.push(num);
            }
            else{
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                
                int res;
                switch (s[i]){
                    case '*':
                        res=b*a;
                        break; 
                        
                    case '/':
                        res=b/a;
                        break;
                    
                    case '+':
                        res=b+a;
                        break;
                    
                    case '-':
                        res=b-a;
                        break;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends
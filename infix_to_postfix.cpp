//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    
    int precedence(char op){
        switch (op){
            case '^':
                return 5;
            case '*':
                return 4;
            case '/':
                return 4;
            case '+':
                return 3;
            case '-':
                return 3;
            default:
                return 0;
        }
    }
    string infixToPostfix(string s) {
        // Your code here
        stack<int>st;
        string str="";
        int len=s.length();
        
        for(int i=0; i<len; i++){
            if((isalpha(s[i]) || isdigit(s[i])) && s[i]!='(' && s[i]!=')'){
                str+=s[i];
            }
            
            else{
                int priority=precedence(s[i]);
                
                if(s[i]==')'){
                     while(!st.empty() && (st.top()!='(')){
                        str+=st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else if((st.empty() ||s[i]=='(' || st.top()=='(' || precedence(st.top()) < priority) && (s[i]!=')' )){
                    st.push(s[i]);
                }
            
                else{
                    while(!st.empty() && (precedence(st.top()) >= priority)&&(st.top()!='(')){
                        str+=st.top();
                        st.pop();
                    }
                   
                    st.push(s[i]);
                }
                
            }
            
        }
        
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        
        return str;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends
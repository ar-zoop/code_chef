class Solution {
public:
    bool isPalindrome(string s) {
        string st="";
        for (int i=0; i<s.length();i++){
            if(isalnum(s[i])){
                st+=tolower(s[i]);
            }
        }
        // cout<<st<<endl;
        int n=st.length()-1;
        for(int i=0;i<st.length()/2;i++){
            if(st[i]!=st[n-i]) return 0;
        }
        
        return 1;
    }
};
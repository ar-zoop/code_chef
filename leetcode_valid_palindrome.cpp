class Solution {
public:
    bool isPalindrome(string s) {
        stack <char> st;
        // if(s==" ") return 1;
        for (int i=0; i<s.length();i++){
            if(isalnum(s[i])){
                st.push(tolower(s[i]));
            }
        }
        for(int i=0; i<s.length();i++){            
            if(isalnum(s[i])){
                if(st.empty()) return 0;
                char a = tolower(s[i]);
                // cout<<st.top()<<"=="<<a<<endl;
                if((st.top())!=a) return 0;
                st.pop();
            }
        }
        return 1;
    }
};
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int start=0, end=0, count=p.length(), s_len=s.length(), min_win_size=INT_MAX, p_len=p.length();
        string res="-1";
        vector<char>need(26, 0), have(26,0);
        // map<char,  int> need, have;
        for(int i=0; i<p_len; i++){
            need[p[i]-'a']++;
        }
        while(true){
            bool f1=false, f2=false;
            while(end<s_len && count>0){
                f1=true;
                if(need[s[end]-'a']>0){
                    have[s[end]-'a']++;
                    if(have[s[end]-'a']<=need[s[end]-'a']){
                        count--;
                    }
                }
                end++;
            }
            while(start<=end  && count==0){
                f2=true;
                if(need[s[start]-'a']>0 && need[s[start]-'a']<have[s[start]-'a']){
                    have[s[start]-'a']--;
                    start++;
                }
                
                else if(need[s[start]-'a']>0 && need[s[start]-'a']==have[s[start]-'a']){
                    have[s[start]-'a']--;
                    start++;
                    count++;
                    if((end-start)<min_win_size){
                        res.assign(s.begin()+(start-1), s.begin()+end);
                        min_win_size=end-start;
                    }
                }
                
                else{
                    start++;
                }
            }
            if(f1==false && f2==false) break;
        }
        return res;
    }
};
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int start=0, end=0;
        string res="-1";
        int res_len=INT_MAX;
        map<char,int> need;
        map<char, int> have;
        int s_size=s.length();
        int count=p.size();
        for(int i=0 ;i<count; i++){
            if(need.find(p[i])==need.end()){
                need[p[i]]=1;
            }
            else{
                p[i]++;
            }
        }
        while(start<s_size){
            if(count>0){
                if(have.find(s[end])==have.end()){
                    have[s[end]]=1;
                }
                else{
                    have[s[end]]++;
                }
                if(need.find(s[end])!=need.end() && need[s[end]]>=have[s[end]] ){
                    count--;
                }
                if(count!=0)
                    end++;
            }
            if(count==0){
                if(res=="-1"){
                    res.assign(s,start,end);
                    res_len=end-start+1;
                }
                if(need.find(s[start])==need.end()){
                    have[s[start]]--;
                }
                else{
                    if(need[s[start]]<have[s[start]]){
                        have[s[start]]--;
                    }
                    else{
                        if(res_len>(end-start+1)){
                            res.assign(s,start,end);
                            res_len=res.length();
                        }
                        count++;
                        have[s[start]]--;
                        end++;
                    }
                }
                start++;
            }
            
        }
        
        return res;
        
        
    }
};
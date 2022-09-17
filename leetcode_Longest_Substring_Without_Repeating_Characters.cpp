class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count=0, maxi=0, sptr=0;
        map<char,int>mpp;
        for(int eptr=0;eptr<s.length();eptr++){
            if(sptr==eptr){
                mpp[s[eptr]]=1;
                count=1;
                maxi=max(count, maxi);
            }
            else if(mpp.find(s[eptr])==mpp.end() || mpp[s[eptr]]==0){
                mpp[s[eptr]]=1;
                count++;
                maxi=max(count, maxi);
            }
            else{
                mpp[s[eptr]]++;
                count++;
                while(mpp[s[eptr]]>1){
                    mpp[s[sptr]]--;
                    sptr++;                    
                    // cout<<s[eptr]<<"="<<mpp[s[eptr]]<<" ";
                    count--;
                }
            }
        }
        return maxi;
    }
};
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=1; i<n ;i++){
            int low=i-1;
            int high=i;
            while(low>=0 && high<n && s[low]==s[high]){                
                    low--;                
                    high++;
                    count++;                
            }
            
            low=i-1;
            high=i+1;
            while(low>=0 && high<n && s[low]==s[high]){  
                    low--;
                    high++;
                    count++;                
            }
            
        }
        return count+n;
    }
};
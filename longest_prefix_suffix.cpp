class Solution{
  public:		
	int lps(string s) {
	    int s_len=s.length();
	    int lps[s_len]={0};
	    int start=0;
	   
	    int i=1;
	    while(i<s.length()){
            if(s[start]==s[i]){
                lps[i]=start+1;
                start++;
                i++;
            }
            else{
                if(start>0){
                        
                        start=lps[start-1];
                        // [start]=
                    }
                else{
                    i++;
                }
            }
        }
	    return lps[s_len -1];
	    
	}
};
class Solution {
    lps(s){ 
        //code here
        let lps= new Array();
        let i=0,j=1;
        let sLen=s.length;
        lps[0]=0;
        while(j<sLen){
            if(s[j]==s[i]){
                lps[j]=i+1;
                i++;
                j++;
            }
            else if(i==0){
                // j--;
                lps[j]=0;
                j++;
            }
            else{
                i=lps[i-1];
            }
        }
      
        return lps[sLen-1];
        
    }
}
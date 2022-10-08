class Solution {
public:
    
    int strStr(string haystack, string needle) {
        int n_len=needle.length();
        double sum=0;
        int n=n_len-1;
        double sub=1;
        int h_len=haystack.length();
        if(n_len > h_len) return -1;
        while(n--){
            sub=(sub*10);
        }
        for(int i=0;i<n_len;i++){
            sum=(sum*10)+(needle[i]-96);
        }       
        
        
        int str_len=0;
        double temp_sum=0 ;
        int i=0;
        int start=0;
        for(int i=0;i<h_len;i++){
            if(str_len<n_len){
                temp_sum=(temp_sum*10)+(haystack[i]-96);
                str_len++;
               // cout<<temp_sum<<endl;
            }
            
            
            
            else if(start<(h_len-n_len)){
                temp_sum=temp_sum-((haystack[start]-96)*sub);  
                start++;
                temp_sum=(temp_sum*10)+(haystack[i]-96);
                // cout<<temp_sum<<endl;
            }
            if(str_len==n_len && sum==temp_sum){
                return start;
            }
        }
        
        return -1;
    }
};
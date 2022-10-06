class Solution
{
    
    public:
        vector <int> search(string pat, string txt)
        {
            //code hee.
            vector<int> res;
            int n=pat.length();
            int lps[n]={0};
            int start=0;
            for(int i =1;i<pat.length();i++){
                if(pat[start]==pat[i]){
                    
                    lps[i]=start+1;
                    start++;
                }
                else{
                    start=0;
                    lps[i]=0;
                }
            }
           

            start=0;
            int pat_len=pat.length();
            int i=0;
            while(i<txt.length()){
                if(start<pat_len && txt[i]==pat[start]){
                    start++;
                    if(start==pat_len){
                        res.push_back(i-pat_len+2);
                        start=lps[start-1];
                        
                
                    }
                    i++;
                   
                }
                else{
                    // cout<<"here";
                       if(start>0)
                            start=lps[start-1];
                        else{
                            i++;
                        }
                   
                    // cout<<start<<endl;
                    
                   
                }
            }
            return res;
        }
     
};
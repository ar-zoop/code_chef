class Solution{
    public:
    bool match(string wild, string pattern)
    {
        int w=wild.length();
        int p=pattern.length();
        int start=0, end=0;
        int i=0, j=0;
        while(i<w){
            int start,end;
            if(wild[i]=='?') {
                i++;
                j++;
            }
            else if(wild[i]=='*'){
                if(i<p-1)
                i++;
                start=i;
                while(wild[i]!='*' && i<w){
                    i++;
                }
                if(start==w-1){
                    return true;
                }
                end=i;
                int temp=start;
                while(j<p && start<end){
                    if(wild[j]==pattern[start]){
                        j++;
                        start++;
                    }
                    else{
                        start=temp;
                        j++;
                    }
                }
                if(start!=end){
                    cout<<"here";
                    return false;
                }
            }
            else{
                if(wild[i]==pattern[j]){
                    i++;
                    j++;
                }
                else{
                    
                    return false;
                }
            }
        }
        if(j==p)
            return true;
        else 
            return false;
    }
};
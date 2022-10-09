class Solution

{
    public:
    int transform (string A, string B)
    {
        //code here.
        int freq[52]={0};
        if(A.length()!=B.length()) return -1;
        for(int i=0;i<B.length();i++){
            if(isupper(A[i])){
                freq[A[i]-39]++;
            }
            else
                freq[A[i]-96]++;
            if(isupper(B[i])){
                freq[B[i]-39]--;
            }
            else
                freq[B[i]-96]--;
        }
        for(int i=0;i<52;i++){
            if(freq[i]!=0) return -1;
        }
        int b=B.length()-1, a=A.length()-1;
        int count=0;
        while(b>=0 && a>=0){
            if(A[a]==B[b]){
                a--;
                b--;
            }
            else{
                count++;
                a--;
            }
        }
        return count;
    }
};
bool kPangram(string str, int k)
{
    // code here 
    int alpha[26]={0};
    for (int i=0;i<str.length();i++){
        
            alpha[(int)str[i]-97]++;
        
    }
    int count=0,ava=0;
    for(int i=0;i<26;i++){
        // cout<<alpha[i]<<" ";
        if(alpha[i]>0){
            ava+=alpha[i]-1;
        }
        if(alpha[i]==0){
            count++;
        }
        
    }
    if (count<=k && ava>=count)
        return 1;
    else return 0;
}
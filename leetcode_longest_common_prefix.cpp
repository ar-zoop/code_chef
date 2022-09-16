class Solution {
public:
    string compare(string str1, string str2){
        int n;
        string common="";
        if(str1.length() < str2.length()){
            n=str1.length();
        }
        n=str2.length();
        for(int i=0;i<n;i++){
            if(str1[i]==str2[i]){
                common+=str1[i];
            }
            else return common;
        }
        return common;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        string str1, str2, common="";
        if(strs.size()>0){
            str1=strs[0];
            if(strs.size()>1){
                str2=strs[1];
                common=compare(str1,str2);
                if(strs.size()>2){
                    for(int i=2 ; i<strs.size() ;i++){
                        common=compare(common, strs[i]);
                    }
                }
            }
            else{
                common=strs[0];
            }
            
        }
        return common;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[27]={0};
        //-97
        if(s.length()!=t.length()) return 0;
        for(int i=0; i<s.length(); i++){
            freq[s[i]-97]++;
            freq[t[i]-97]--;
        }
        for(int i=0; i<26;i++){
            if(freq[i]!=0) return 0;
        }
        return 1;
    }
};
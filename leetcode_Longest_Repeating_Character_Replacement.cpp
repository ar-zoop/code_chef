class Solution {
public:
    int characterReplacement(string s, int k) {
        int sum=0, max0=0, sptr=0, maxi=0,eptr=0;
        map<char,int> freq;
        while(eptr<s.length()){
            if(sptr>eptr){
                sptr=eptr;
                eptr++;
            }
            
            if(freq.find(s[eptr])==freq.end()){
                freq[s[eptr]]=1;                 
            }
            else{
                freq[s[eptr]]++;                 
            }
            sum++;
            if(freq[s[eptr]]>max0){
                max0=freq[s[eptr]];               
            }
            if(sum-max0<=k){
                maxi=max(sum,maxi);
            }
            else{
                while(sum-max0>k && sptr<=eptr){
                    freq[s[sptr]]--;
                    sptr++;
                    sum--;
                    auto pr = std::max_element(freq.begin(), freq.end(), [](const auto &x, const auto &y) {
                        return x.second < y.second;
                    });
                }
            }
            eptr++;
        }
        return maxi;
    }
};
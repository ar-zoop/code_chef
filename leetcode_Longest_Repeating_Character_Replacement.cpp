bool compare(vector<int> v1, vector<int> v2){
        return v1[0]>v2[0];
}
class Solution {
public:
    
    int characterReplacement(string s, int k) {
        map<pair<int,char>,int> mpp;
        int sptr=0, count=0;
        for(int i=0 ;i <s.size(); i++){
            if (i>0 && s[i]!=s[i-1]) sptr++;
            
            if(mpp.find(make_pair(sptr,s[i]))==mpp.end()){
                mpp[make_pair(sptr,s[i])]=1;
                count++;
            }
            
            else if(i>0 && s[i]==s[i-1]){
                mpp[make_pair(sptr,s[i])]++;
            }
        }
         map<pair<int,char>,int> :: iterator imp;
        
        vector<vector<int>> vec( count , vector<int> (2, 0)); 
        int i=0;
        for(imp=mpp.begin(); imp!=mpp.end(); imp++){
            // cout<<(imp->first).second <<" "<<imp->second<<endl;
            vec[i][0]=imp->second;
            vec[i][1]=(imp->first).second;
            i++;
        }
        sort(vec.begin(), vec.end(), compare);
        for(int i=0 ; i<vec.size(); i++){
            cout<<vec[i][0]<<"="<<vec[i][1]<<endl;
        }
        return 0;
    }
};
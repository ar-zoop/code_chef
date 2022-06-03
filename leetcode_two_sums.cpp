class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> :: iterator itr;
        map <int,int> mpp;
        map <int,int> :: iterator imp;
        vector <int> ans;
        int pos=-1;
        int temp_res[2];
        for (itr=nums.begin(); itr!=nums.end() ;itr++){            
            if(mpp.find(*itr) == mpp.end())
                mpp[*itr]=1;
            else
                mpp[*itr]++;
        }
        
        if(target%2==0){
            
            if((mpp.find(target/2))!=mpp.end() && mpp[target/2]>=2){
                temp_res[++pos]=target/2;
                temp_res[++pos]=target/2;
                goto jump;
            }
        }
        
        for(imp=mpp.begin();imp!=mpp.end();imp++){
            
            
                int num1=(*imp).first;
                int search=target-num1;
                if(mpp.find(search)!=mpp.end()){
                    temp_res[++pos]=num1;
                    temp_res[++pos]=search;

                    break;
                }

            
        }
        
        
       jump: int count=-1;
        for (itr=nums.begin();itr!=nums.end();itr++){
            count++;
            if(temp_res[0]==(*itr)){
                ans.push_back(count);
                
            }
             else if(temp_res[1]==(*itr)){
                ans.push_back(count);
            }
        }
        return ans;
    }
};
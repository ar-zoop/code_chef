//MO's algorithm application
int rootN;
bool compare(vector<int> A, vector<int> B){
        if(A[0]/rootN == B[0]/rootN)
            return A[1]>B[1];
        
        else return A[0]<B[0];
        
    }
class Solution {
// public :
    
public:
    
	vector<int>solveQueries(vector<int>nums, vector<vector<int>>Queries, int k){
	    vector <int> ans(Queries.size(),0);
	    // sqrtl decomposition of the array
	    rootN=sqrtl(Queries.size());
	    //sort the queries array
	    for(int i=0 ;i <Queries.size(); i++){
	        Queries[i][2]=i;
	       // cout<<Queries[i][2]<<endl;
	    }
	    
	    sort(Queries.begin(), Queries.end(), compare);
	    //traverse the sorted queries and perform the operation
	    map <int, int> mpp;
	    int curr_l=0, curr_r=-1;
	    for(int i=0 ;i <Queries.size(); i++){
	        int l=Queries[i][0]-1;
	        int r= Queries[i][1]-1, idx=Queries[i][2];
	        
	        //case 1: curr_r < r || adding elements to 0 sum
	        
            while(curr_r < r){
                curr_r++;
                if(mpp.find(nums[curr_r])==mpp.end()){
                    mpp[nums[curr_r]]=1;
                }
                else mpp[nums[curr_r]]++;
            }
            
            //case 2: curr_l > l|| adding elements to sum 0
            while(curr_l > l){
                curr_l--;
                if(mpp.find(nums[curr_l])==mpp.end()){
                    mpp[nums[curr_l]]=1;
                }
                else mpp[nums[curr_l]]++;       
            }
            
            //case 3: curr_l < l
            
            while(curr_l < l){
                
                mpp[nums[curr_l]]--; 
                // cout<<mpp[nums[curr_l]]<<endl;
                
                curr_l++;
                
                
            }
            
            //case 4: curr_r > r
            while(curr_r > r){
                
                   mpp[nums[curr_r]]--;
                //   cout<<mpp[nums[curr_r]]<<endl;
                    
                
                curr_r--;
            }
        
            int count=0;
            map<int, int>::iterator imp;
            for(imp=mpp.begin(); imp!=mpp.end(); imp++){
                if(imp->second >= k) count++;
            }
            ans[idx]=count;
	    }
	    //return the answer vector
	    return ans;
	}
};
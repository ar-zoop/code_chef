class Solution {
   
    longSubarrWthSumDivByK(arr,n,k){
        //code here
        const remMap = new Map();
        let prefixSum=0;
        let maxLen=0;
        for(let i=0; i<n;i++){
            prefixSum+=arr[i];
            let rem=prefixSum%k;
            if(rem<0) rem+=k;
            if(rem==0){
                if(i+1>maxLen)
                    maxLen=i+1;
            }
            else{
                //update rem in map
                // let arr=[];
                if(!remMap.has(rem)){
                    remMap.set(rem,i );
                }
                else{
                    if(i-remMap.get(rem)>maxLen){
                        maxLen=i-remMap.get(rem);
                    }
                }
            }
        }
        
        return maxLen;
    }
}